# AI handoff (ChatGPT planner <-> Codex implementer)

This file is the message board between the **planner** (ChatGPT with @GitHub, reads the repo) and the
**implementer** (Codex, works locally in `F:\SelfmadeTools\JFG_Recomp\JFGRecomp` with the ROM).
GitHub is the only connection between them, so everything that the other side must know goes here.

Rules
- Read this file and `decomp/docs/RECOMP.md` ("CURRENT STATUS") before starting.
- Planner writes a new entry under **Open task** (replaces the previous one). Implementer answers under
  **Last result** (replaces the previous one) and pushes. Older entries move to **History** as one line each.
- Technical findings belong in `decomp/docs/RECOMP.md` (dated log + CURRENT STATUS). This file only holds the
  current task, the current answer and short questions. Only `decomp/docs/RECOMP.md` in this repo is maintained
  (not the copy in the local JFG_Decomp folder).
- Mark facts vs. assumptions. The real code wins over any plan.
- Never commit ROMs or ROM-derived files (`RecompiledFuncs/`, `rsp/n_aspMain.cpp`, `*.z64`, extracted microcode).

---

## Open task (aktiv): Debug quick start: intro skip, cutscene skip, direct level load (2026-10-15)

- **Status:** Teilweise umgesetzt. Nicht fertig: siehe "Last result" unten (Done-when-Punkte 1-3, 5, 9 offen).
- **Goal:** Reproduzierbarer Debug-Schnellstart für den nativen Windows-Port: `--jfg-skip-intro`, `--jfg-skip-cutscenes`,
  `--jfg-level goldwood`, optional `--jfg-test-start goldwood`. Ein echter Direct Level Load ist das Hauptziel;
  schnelleres Durchklicken der Menüs nur Zwischenlösung. Alles Debug, standardmäßig aus.
- **Analysis / root cause:** Die Default-Route (tools/run_to_goldwood.ps1) lädt die Level-Sequenz 0x0, 0x15D, 0x7F, 0x16D
  (Charakterwahl, char 1), 0x5D, 0x5C. Goldwood-Gameplay erscheint bei etwa 105-112 s. Ein Direktsprung aus dem
  Haupt-Thread hängt laut früherer Notiz (NONMATCHING_BUILD.md:158). Annahmen zu Overlays, Save-State und
  Initialisierungsreihenfolge sind nicht geprüft.
- **Planned changes:** Phase 1 Startup-/Level-Loader untersuchen (main.c, runLink.c, sched.c, controller.c,
  jfg.us.toml, Level-/Spawn-/Save-/Cutscene-Funktionen). Phase 2 CLI-Parser mit Fehlermeldung für unbekannte Level,
  kein stiller Fallback. Phase 3 Intro-Skip nach der Initialisierung. Phase 4 Direct Level Load Goldwood: gültiger
  Spawn außerhalb des Wassers, keine laufende Cutscene, kein Savegame-Schreiben. Phase 5 Cutscene-Skip nur für die
  Goldwood-Landungssequenz, falls generisch nicht sicher; keine globalen Hooks, keine Timer auf null setzen.
  Phase 6 tools/test_debug_start.ps1. Phase 7 Determinismus protokollieren (RNG, Zeitinitialisierung).
- **Must not change:** Keine ROMs, RecompiledFuncs/, rsp/n_aspMain.cpp, Savegames committen. Normaler Start ohne Argumente
  unverändert. Keine VI-/Delta-Manipulation, keine 60-Hz-Logik, keine RT64-Änderung ohne Notwendigkeit, keine
  pauschale Deaktivierung von Cutscene-Triggern, keine permanenten Cheats.
- **Tests:** TEST 1 normaler Start; TEST 2 Intro-Skip; TEST 3 `--jfg-level goldwood` (Player, Kamera, HUD, Bewegung,
  Sprung, Schuss); TEST 4 mit `--jfg-skip-cutscenes`; TEST 5 zehn aufeinanderfolgende Starts (Start bis erster
  steuerbarer Frame, Spawn, Kamera, Game-State, Updates, Abstürze); TEST 6 30/60-Hz mit identischem Start; TEST 7
  Screenshots; TEST 8 build_jfg.bat build.
- **Done when:** 1 Direct Level Load Goldwood funktioniert. 2 Intro-Skip funktioniert oder Einschränkung nachgewiesen.
  3 Cutscene-Skip für Goldwood oder ausdrücklich als nicht sicher dokumentiert. 4 Spieler steuerbar nach Debug-Start.
  5 Zehn Starts hintereinander OK. 6 Normaler Start unverändert. 7 Keine Savegames ungewollt verändert. 8 Testskript
  vorhanden. 9 Startzeiten und Screenshots dokumentiert. 10 build_jfg.bat erfolgreich. 11 RECOMP.md datierter Eintrag.
  12 CURRENT STATUS aktualisiert. 13 Last result ausgefüllt. 14 Diff geprüft. 15 Commit nach jfg/main gepusht
  (marvelmaster/JFG-Recomp, nie origin/BanjoRecomp).
- **Anweisungen an Codex:** Vor jeder Änderung den echten Code prüfen. Keine geratenen ROM-Adressen oder Speicherwerte.
  Bei lib/-Änderungen lib-patches neu erzeugen. Die genehmigte Instrumentierung in N64ModernRuntime/RT64 erst nach
  diesem Task fortsetzen. Nach dem Push auf den Planner warten.

## Backlog (PAUSIERT, nicht erledigt): Experimental 60 Hz gameplay
Der vollständige Text dieses Tasks steht unverändert unten. Stand und Messungen: RECOMP.md Einträge 2026-10-15
(afternoon, late afternoon). Commits: 9444447, ed1f20d.

**Titel:** Experimental 60 Hz gameplay: audit, A/B validation and targeted fixes (2026-10-15)

- **Goal:**
  Die bereits implementierte optionale 60-Hz-Spiellogik für Jet Force Gemini fertigstellen und nachweisbar validieren.

  Ziel ist eine Verringerung der Eingabeverzögerung durch häufigere echte Spiellogik-Updates, ohne dass Bewegung, Sprünge, Animationen, Timer, Gegner, Zwischensequenzen oder andere Spielsysteme schneller ablaufen.

  Die Option "60 Hz Gameplay" bleibt im General-Tab, ist standardmäßig AUS und ausdrücklich als "Experimental" gekennzeichnet.

  Es geht nicht um bloße RT64-Frame-Interpolation, künstlich verdoppelte VI-Zähler oder eine Beschleunigung der Spielzeit.

  Erfolg bedeutet:
  - 60-Hz-Modus: bei ausreichender Leistung ungefähr 60 echte Updates pro Sekunde.
  - Standardmodus: unverändertes Originalverhalten.
  - Vergleichbare Spielgeschwindigkeit pro realer Sekunde.
  - Keine neuen Hänger, Speicherfehler oder Scheduler-Deadlocks.
  - Messbare Verringerung der Input-to-visible-response-Latenz, sofern die tatsächliche Renderpipeline dies zulässt.

  Ein Modus mit nachweislich abweichender Spielgeschwindigkeit darf nicht als fertig bezeichnet werden.

- **Analysis / root cause (facts with file:line, assumptions marked):**

  WICHTIG: Der folgende Stand basiert auf GitHub main vom 2026-10-15. Vor Beginn git pull und alle Angaben gegen den tatsächlichen lokalen Code einschließlich generierter US-ROM-Funktionen prüfen. Der echte Code hat Vorrang.

  BESTÄTIGT AUS DEM REPO:

  1. decomp/docs/RECOMP.md:
     - 12:12: Zwei unabhängige Begrenzungen gefunden.
     - 12:17: Ein Scheduler-Wartezyklus plus viFrameSync verursachte zwei serielle Retrace-Wartevorgänge.
     - 12:19: Überarbeitete Hooks erreichen delta=1 und ungefähr 16,7 ms pro Update.
     - Vollständiger Goldwood-A/B-Vergleich fehlt weiterhin.
     - Die bekannte Goldwood-Landungssequenz kann gelegentlich hängen; dieses Problem existiert bereits unabhängig von 60 Hz.

  2. decomp/recomp/jfg.us.toml:
     - joyRead, 0x80043130:
       jfg_gameplay_tick(rdram, ctx)
     - __scHandleRetrace, 0x800506E8:
       Bei aktiviertem 60 Hz ctx->r1 = 0.
     - __scTaskComplete, 0x80050A58:
       Bei aktiviertem 60 Hz ctx->r1 = 0.
     - viFrameSync, 0x80055104:
       jfg_frame_sync_limit(rdram, ctx).

     Die beiden Scheduler-Hooks umgehen die zusätzliche Completion-/FrameCount-Begrenzung. viFrameSync bleibt für VI-Pacing und Swap zuständig.

     KRITISCHE PRÜFUNG:
     Für jeden Hook anhand der tatsächlichen generierten US-Instruktionen und des Kontrollflusses verifizieren:
     - Ist ctx->r1 wirklich das richtige Register?
     - Wird nur die beabsichtigte Bedingung beeinflusst?
     - Bleiben Task-Ownership und Completion-Nachrichten korrekt?
     - Bleibt der originale Codepfad bei deaktivierter Option vollständig erhalten?
     - Sind die Hook-Adressen und Registerannahmen auch nach Regeneration korrekt?

     Die Hook-Adressen nicht allein anhand des Decomp-C als bewiesen betrachten.

  3. decomp/src/gameVi.c:
     viFrameRateReset() initialisiert den adaptiven Mindestwert auf 2.
     viFrameSync() zählt tatsächliche Retraces, passt den Mindestwert adaptiv an, führt osViSwapBuffer aus und wartet abschließend auf eine Retrace-Nachricht.

     Wichtig:
     - Tatsächlich gemessene VI-Zeit erhalten.
     - Keine künstliche Delta-Manipulation.
     - Abschließendes Swap-/Retrace-Pacing nicht entfernen.
     - Adaptive Zustände und Reset-Pfade prüfen.

  4. src/main/main.cpp:
     - jfg_60hz_active ist atomic<bool>.
     - jfg_60hz_enabled() liest den Zustand.
     - jfg_gameplay_tick() liest die gespeicherte Option bei joyRead.
     - JFG_60HZ_GAMEPLAY=0/1 überschreibt die Einstellung für Tests.
     - JFG_TRACE_GAMEPLAY protokolliert Frame, Zeit, Delta und Spielerposition.
     - jfg_frame_sync_limit() setzt den VI-Mindestwert bei 60 Hz auf 1 und nach Abschalten pauschal auf 2.

     RISIKO:
     Der ursprüngliche adaptive Mindestwert kann 1, 2 oder 3 sein. Ein pauschales Zurücksetzen auf 2 ist keine exakte Wiederherstellung des vorherigen Zustands.

     Weiteres Risiko:
     Der Modus wird bei joyRead aktualisiert. Scheduler-Hooks können den Atomic-Wert zu einem anderen Zeitpunkt lesen. Ein Moduswechsel innerhalb eines laufenden Frames könnte deshalb verschiedene Regeln für denselben Frame verwenden.

     Atomic-Zugriff allein beweist keine sichere Frame-Grenze.

  5. decomp/src/main.c:
     Der Hauptloop übergibt delayDat an verschiedene Spielsysteme.

     Laut bisheriger Analyse wird die Display List der vorherigen Iteration vor dem neuen Input verarbeitet. Deshalb beträgt die ursprüngliche Eingabe-zu-sichtbarem-Ergebnis-Verzögerung ungefähr einen Spielframe zusätzlich zur Abtastwartezeit.

     Zu prüfen:
     - Woher kommt delayDat exakt?
     - Welche Einheit hat delayDat?
     - Ist delayDat tatsächlich das Ergebnis von viFrameSync?
     - Welche Systeme bekommen den Integer- und welche den Float-Zeitschritt?
     - Gibt es Clamps, Rundungen oder Sonderfälle für delta=1?
     - Wie verhalten sich verzögerte Frames mit delta>1?

  6. decomp/src/controller.c:
     joyRead(..., updateRate) und die Weitergabe des Zeitschritts prüfen.

     Insbesondere:
     - Analogstick-Verarbeitung
     - Button-Pressed-/Released-Flanken
     - gehaltene Tasten
     - Wiederholungsraten
     - Mouse-Aim-Hooks
     - Input-Scripting
     - Verhalten bei einem Moduswechsel

  7. decomp/src/sched.c:
     __scHandleRetrace und __scTaskComplete mit dem generierten Code abgleichen.

     Prüfen, ob die höhere Updatefrequenz:
     - doppelte Task-Completion auslösen kann,
     - noch aktive Tasks überschreibt,
     - Nachrichtenqueues überfüllt,
     - die Render-/Audio-Synchronisierung verändert,
     - bei langsamer GPU zu unerwartetem Verhalten führt.

  8. Bekannte framebasierte Ausnahme:
     trackUpdateTextureScroll addiert Scroll-Deltas pro Aufruf ohne Zeitschritt.

     Erwartetes Risiko: Texturen scrollen bei 60 Updates/s schneller.

     Datei/Funktion und Aufrufkette lokal nachweisen, anschließend gezielt korrigieren.

  NOCH NICHT BEWIESEN — SYSTEMATISCH PRÜFEN:

  A. Animation:
     decomp/src/anim.c
     decomp/src/models.c

     Relevante Funktionen und Aufrufketten ermitteln:
     - Animation-Frame-Fortschritt
     - Animation-Interpolation
     - Animation-Blending
     - modelbezogene Timer
     - einmalige Animationsevents
     - gen_anim_data / modGenAnimMatrices

     Risiko:
     Animationen oder Übergänge verwenden möglicherweise konstante Schritte pro Update.

     Keine Änderungen am bestehenden RT64-Modell-Fix vornehmen, solange kein Zusammenhang mit 60 Hz nachgewiesen ist.

  B. Bewegung und Physik:
     decomp/src/charControl.c
     Spieler-Overlays, insbesondere boyControl und seine Bewegungszustände.

     Prüfen:
     - Geh- und Laufgeschwindigkeit
     - Beschleunigung und Bremsen
     - Schwerkraft
     - Sprungimpuls
     - vertikale Geschwindigkeit
     - Sprunghöhe und Flugdauer
     - Kollisionen
     - Wasserbewegung
     - Knockback und Rückstoß

     Besonders auf konstante Additionen, Multiplikationen und Dämpfungsfaktoren pro Aufruf achten.

  C. Kamera:
     decomp/src/camera.c
     decomp/src/charControl.c
     func_8002CF78
     func_8002B378

     Prüfen:
     - Kamerafolge
     - exponentielle Glättung
     - Drehgeschwindigkeit
     - Shake
     - Kollision
     - Mouse Camera

     Ein fixer Glättungsfaktor pro Frame ist nicht automatisch zeitinvariant.

  D. Partikel und Effekte:
     decomp/src/particles.c
     decomp/src/fx.c

     Prüfen:
     - Spawn-Raten
     - Lebensdauer
     - Geschwindigkeiten
     - Gravitation
     - Transparenz/Fade
     - Zufallsereignisse

     Besonders Aufrufe von RNG pro Update prüfen.

  E. Zwischensequenzen:
     Animation-Sequence-/Camera-Path-System und zugehörige Overlays.

     Prüfen:
     - Gesamtdauer
     - Triggerzeitpunkte
     - Dialog-/Untertitelzeiten
     - Kamerapfade
     - einmalige Events
     - Übergänge zwischen Spielzuständen

  F. Audio:
     Audio-Update und Scheduler-Synchronisierung.

     Prüfen:
     - Musiktempo
     - Sample-/Buffer-Submission
     - Sound-Trigger
     - Wiederholungen
     - mögliche Queue-Überläufe
     - Cutscene-Audio-Synchronisierung

     Audio wurde bisher nicht hörend validiert. Nicht als funktionierend behaupten, wenn nur Logs geprüft wurden.

  G. Gegner-KI:
     Overlays und zentrale Object-Update-Funktionen.

     Prüfen:
     - Angriffsraten
     - Projektilgeschwindigkeit
     - Cooldowns
     - Pathfinding
     - Zustandsübergänge
     - KI-Zufallsentscheidungen

     Keine pauschale Annahme treffen, dass alle Overlays delta-korrekt sind.

- **Planned changes (files, functions, code):**

  PHASE 1 — Codeaudit vor Änderungen

  1. Zuerst README.md, HANDOFF.md und RECOMP.md CURRENT STATUS sowie die neuesten Einträge lesen.

  2. Arbeitsbaum und Git-Stand prüfen.

  3. Folgende Dateien gezielt untersuchen:
     - src/game/config.cpp
     - src/main/main.cpp
     - decomp/recomp/jfg.us.toml
     - decomp/src/main.c
     - decomp/src/sched.c
     - decomp/src/gameVi.c
     - decomp/src/controller.c
     - decomp/src/anim.c
     - decomp/src/models.c
     - decomp/src/charControl.c
     - decomp/src/camera.c
     - decomp/src/particles.c
     - decomp/src/fx.c
     - relevante lokale Overlays
     - tools/test_60hz_gameplay.ps1
     - tools/analyze_gameplay.py

  4. Für jeden nachgewiesenen Fehler dokumentieren:
     Datei, Funktion, möglichst Zeile/Adresse, beobachtetes Verhalten, Ursache, geplante Korrektur.

  5. Keine breitflächige Konvertierung sämtlicher Animationen oder Physikformeln auf Verdacht.

  PHASE 2 — Laufzeitumschaltung absichern

  src/main/main.cpp:
  jfg_gameplay_tick()
  jfg_60hz_enabled()
  jfg_frame_sync_limit()

  Den Übergang zwischen 30 und 60 Hz analysieren.

  Bevorzugte Lösung:
  Modusänderungen nur an einer nachweislich sicheren Frame-/VI-Grenze wirksam machen, an der die zugehörigen Scheduler-Bedingungen konsistent bleiben.

  Wenn das nicht zuverlässig möglich ist:
  Option erst beim nächsten Spielstart wirksam machen oder einen Neustart verlangen.

  Keine scheinbar sichere Live-Umschaltung anbieten, wenn Race Conditions oder Scheduler-Inkonsistenzen offen sind.

  Die vorhandene atomic<bool>-Struktur darf erhalten bleiben, wenn die Frame-Grenzen korrekt abgesichert sind.

  Für den adaptiven VI-Mindestwert:
  - Originalverhalten exakt untersuchen.
  - Nicht blind den Wert 2 als vorherigen Zustand annehmen.
  - Reset und Szenenwechsel berücksichtigen.
  - Sicherstellen, dass bei OFF keine 60-Hz-Restzustände verbleiben.

  PHASE 3 — Zeitschritt und Korrekturformeln

  Grundsatz:
  Zeitbasierte Spielgrößen müssen über dieselbe reale Zeit ungefähr denselben Verlauf besitzen.

  Wenn ein System bereits einen korrekten Delta-Wert verwendet:
  NICHT ändern.

  Wenn ein System pro Update eine konstante Bewegung addiert:
  Den Wert anhand der ursprünglichen Zeiteinheit skalieren.

  Beispiel nur als mathematisches Muster:

      float step = float(delta_vi) / 2.0f;
      position += original_30hz_increment * step;

  Diese Formel nur anwenden, wenn der betreffende Originalpfad tatsächlich für 2 VI pro Referenzupdate ausgelegt ist.

  Nicht global delta durch 2 teilen.

  Bei konstanten Dämpfungsfaktoren:

      effective_factor = powf(original_factor, step);

  Nur anwenden, wenn es sich nachweislich um einen zeitbasierten exponentiellen Faktor handelt.

  Bei Timern:
  - vorhandene delta-basierte Dekremente beibehalten,
  - Nullübergänge und einmalige Trigger prüfen,
  - Rundungsfehler bei kurzen Timern untersuchen.

  Bei Spawn-Raten:
  - nicht einfach jede zweite Aktualisierung überspringen,
  - zeitbasierte Akkumulatoren oder äquivalente Verfahren verwenden, sofern erforderlich.

  Bei RNG:
  - Aufrufhäufigkeit und Spielverhalten dokumentieren,
  - keine unnötige Veränderung der Zufallssequenz im OFF-Modus.

  Bei trackUpdateTextureScroll:
  Den echten Aufrufkontext ermitteln und Scroll-Deltas so skalieren, dass die Strecke pro Sekunde bei 30/60 Hz vergleichbar bleibt.

  PHASE 4 — Testwerkzeuge erweitern

  tools/test_60hz_gameplay.ps1:
  Bestehenden Vergleich beibehalten und gegebenenfalls gezielt erweitern.

  Wichtig:
  - identische Eingabesequenz
  - gleiche Startbedingungen
  - getrennte Logs
  - gleiche reale Messzeitpunkte
  - gleiche Grafik-/Framerate-Einstellungen
  - keine unbeabsichtigte Veränderung der Saves
  - mehrere Wiederholungen

  tools/analyze_gameplay.py:
  Vorhandene Auswertung prüfen und bei Bedarf um quantitative A/B-Kennzahlen erweitern.

  Trace-Ausgaben müssen echte gemessene Werte enthalten, nicht nur geschätzte FPS.

  Falls notwendig, JFG_TRACE_GAMEPLAY um folgende Daten erweitern:
  - monotonic wall-clock timestamp
  - Frame-/Update-Nummer
  - Delta in VI-Ticks
  - Spielerposition XYZ
  - vertikale Geschwindigkeit
  - Grounded-/Jump-State
  - Animations-ID und Animationsfortschritt
  - Game Timer
  - Szenen-/Cutscene-State
  - optional Kamera-Yaw/Pitch

  Nur tatsächlich verifizierte RDRAM-Adressen und Strukturen verwenden.

  Keine geratenen Offsets in produktive Hooks einbauen.

  Diagnoseausgaben begrenzen, damit Logging die 60-Hz-Messung nicht selbst erheblich verlangsamt.

  PHASE 5 — Korrekturen implementieren

  Reihenfolge:
  1. Scheduler-/VI-Sicherheit
  2. Zeitschrittfehler mit messbarer Gameplay-Auswirkung
  3. Animationen und Kamera
  4. Partikel/Texturscrolling
  5. Cutscenes und Audio
  6. Overlay-KI

  Für jede Änderung:
  - Vorher/Nachher-Messung
  - OFF-Regression
  - minimaler Diff
  - Begründung im RECOMP.md-Log

  Wenn ein System nicht zuverlässig korrigiert werden kann:
  Problem dokumentieren, nicht verstecken.

- **Must not change:**

  - Keine ROM-Dateien verändern oder committen.
  - Keine ROM-Ableitungen committen:
    RecompiledFuncs/
    rsp/n_aspMain.cpp
    extrahiertes Microcode-Material
    *.z64
  - Keine Savegames committen.
  - Keine Testlogs/Screenshots als große Binärdateien committen, sofern nicht ausdrücklich nötig.
  - Kein globales Beschleunigen der VI-Zeit.
  - Kein künstliches Verdoppeln der VI-Counter.
  - Keine Änderung des normalen OFF-Modus ohne zwingenden Grund.
  - Keine ungetestete Änderung an Audio-/Scheduler-Ownership.
  - Keine unmotivierte Änderung an RT64.
  - Keine Arbeit am separaten Charaktermodell-Renderingproblem im Rahmen dieses Tasks.
  - Keine breitflächigen Refactorings.
  - Keine Änderungen am lokalen JFG_Decomp-Dokumentationsstand.
  - Keine Entfernung der Kennzeichnung "Experimental".
  - Kein Einschalten von 60 Hz als Standard.

  Änderungen in lib/ nur wenn technisch notwendig.
  Jede Änderung an einem Submodul muss in der entsprechenden Datei unter lib-patches/*.patch reproduzierbar erhalten bleiben.

- **Tests / how to verify (tools/*.ps1, screenshots, traces):**

  TEST 1 — Baseline

  build_jfg.bat ausführen.

  Danach:

      powershell -ExecutionPolicy Bypass -File tools/test_60hz_gameplay.ps1 -Mode both

  Den genauen Aufruf gegebenenfalls an den lokalen Skriptstand anpassen.

  30-Hz- und 60-Hz-Modus separat erfassen.

  Für jeden Lauf dokumentieren:
  - reale Laufzeit
  - Anzahl Gameplay-Updates
  - Updates pro Sekunde
  - Delta-Verteilung
  - VI-Ticks pro Sekunde
  - Zeit bis Goldwood
  - Screenshots
  - Hänger/Abstürze

  Ziel:
  60 Hz erreicht bei ausreichender Leistung ungefähr 60 Updates/s und delta=1 im stabilen Gameplay.

  30 Hz muss sein bisheriges Verhalten behalten.

  TEST 2 — Laufgeschwindigkeit

  Identischer Startpunkt in Goldwood.

  Gleiche Eingabe für mindestens 5 reale Sekunden.

  Aus XYZ-Trace berechnen:

      distance = sqrt(dx*dx + dy*dy + dz*dz)
      speed = distance / elapsed_seconds

  Zusätzlich horizontale XZ-Distanz auswerten.

  30-Hz- und 60-Hz-Werte vergleichen.

  Vorläufige Zielabweichung:
  höchstens 2 % bei stabiler Bewegung ohne Kollision.

  Größere Abweichungen untersuchen und erklären.

  Nicht blind unterschiedliche Startpositionen oder Bewegungszustände vergleichen.

  TEST 3 — Sprung

  Sprung außerhalb des Wassers durchführen.

  Gleicher Startzustand, gleicher Input.

  Messen:
  - Startzeit
  - Ausgangshöhe
  - maximale Höhe
  - Zeitpunkt des Scheitelpunkts
  - Landungszeit
  - gesamte Sprungdauer

  Mindestens 3 Wiederholungen pro Modus.

  Vorläufige Toleranzen:
  - Sprunghöhe: 2 %
  - Sprungdauer: 1 VI-Tick oder ungefähr 16,7 ms, soweit die Messauflösung das zulässt.

  Abweichungen nicht durch unpassende Rundung verdecken.

  TEST 4 — Animation

  Dieselbe Idle-, Lauf- und Sprunganimation vergleichen.

  Messen:
  - Animationsfortschritt pro Sekunde
  - Loop-Dauer
  - Blend-Dauer
  - sichtbare Pose zu gleichen Zeitpunkten

  Screenshots paarweise vergleichen.

  Eine doppelte Updatezahl darf keine doppelte Animationsgeschwindigkeit bedeuten.

  TEST 5 — Timer

  Mindestens einen zuverlässig identifizierten Gameplay-Timer prüfen.

  Gleiche Startwerte und gleiche reale Laufzeit.

  Soll:
  Vergleichbare Timeränderung pro Sekunde.

  Außerdem kurze Timer und einmalige Trigger prüfen.

  TEST 6 — Cutscenes

  Mindestens:
  - Intro-/Menü-Sequenz
  - Goldwood-Landungssequenz

  Messen:
  - Startzeit
  - Endzeit
  - Gesamtdauer
  - wichtige Übergänge
  - Kamera-/Animationszustände

  Screenshots zu denselben relativen Zeiten.

  Die bereits bekannte seltene Goldwood-Hängeursache nicht automatisch 60 Hz zuschreiben.

  Für beide Modi mehrere Läufe durchführen.
  Bei Hängern vorhandenes hang_watch.ps1 verwenden.

  TEST 7 — Effekte und Kamera

  Vergleichen:
  - Texturscrolling
  - Partikelbewegung
  - Partikellebensdauer
  - Kamera-Folgegeschwindigkeit
  - Kamera-Glättung
  - Mouse Camera
  - Mouse Aim

  Screenshots und numerische Traces kombinieren.

  TEST 8 — Gegner und Audio

  Mindestens einen reproduzierbaren Gegnerkontakt testen.

  Angriffsraten, Projektilbewegung und KI-Cooldowns vergleichen.

  Audio auf doppelte Trigger, Aussetzer, Musiktempo und Cutscene-Synchronisierung prüfen.

  Falls keine echte Audio-Wiedergabeprüfung möglich ist, ausdrücklich "not verified by listening" dokumentieren.

  TEST 9 — Umschaltung

  Prüfen:
  - OFF beim Start
  - ON beim Start
  - gespeicherte Checkbox
  - JFG_60HZ_GAMEPLAY=0
  - JFG_60HZ_GAMEPLAY=1
  - ON -> OFF
  - OFF -> ON
  - Szenenwechsel
  - Pause/Menü
  - Neustart

  Falls Live-Umschaltung unsicher ist, sicheren Neustartmechanismus statt riskanter Live-Aktivierung verwenden.

  TEST 10 — Input-Lag

  Mit JFG_TRACE_LATENCY und tools/latency.py messen.

  Wichtig:
  - identische Grafiksettings
  - gleiche Display-Framerate
  - gleiche Eingabesequenz
  - gleiche Messmethodik
  - getrennte Auswertung für 30 und 60 Hz

  Messen:
  - Input-Sampling-Rate
  - Input -> nächste Display List
  - Input -> erste tatsächlich beeinflusste Display List
  - Display List -> Present
  - gesamte Input-to-visible-response-Latenz, soweit messbar

  Nicht die Display List des vorherigen Spielzustands fälschlich als Reaktion auf den aktuellen Input zählen.

  Median, p95 und Stichprobenzahl angeben.

  Ziel:
  Nachweis einer tatsächlichen Latenzreduktion, nicht nur einer höheren Updatefrequenz.

  TEST 11 — Langzeittest und Performance

  Mehrere längere Goldwood-Läufe.

  Prüfen:
  - CPU-/GPU-Last
  - Frame-Pacing
  - Update-Aussetzer
  - Audio-Queues
  - Task-Completion
  - Speicherfehler
  - Hänger
  - Rückfall auf delta>1 unter Last

  Keine Stabilität aus einem einzigen erfolgreichen Lauf ableiten.

- **Done when:**

  1. Der tatsächliche lokale Code wurde vollständig gegen den Plan geprüft.

  2. Scheduler-Hooks, VI-Pacing und Delta-Herkunft sind mit konkreten Dateien, Funktionen und relevanten Adressen dokumentiert.

  3. Laufzeitumschaltung ist nachweislich sicher oder wird bewusst auf einen sicheren Neustart begrenzt.

  4. Die A/B-Messung zeigt, ob Bewegung, Sprünge, Animationen, Timer und Cutscenes bei 60 Hz dieselbe reale Geschwindigkeit behalten.

  5. Nachgewiesene 60-Hz-spezifische Fehler wurden gezielt korrigiert oder als offene Einschränkung dokumentiert.

  6. Die normale 30-Hz-Konfiguration zeigt keine Regression.

  7. 60-Hz-Updatefrequenz und Input-Lag wurden separat gemessen.

  8. Der Build mit build_jfg.bat ist erfolgreich.

  9. tools/test_60hz_gameplay.ps1 wurde ausgeführt und die Ergebnisse inklusive Screenshots ausgewertet.

  10. Die Option bleibt experimentell und standardmäßig aus.

  11. decomp/docs/RECOMP.md enthält einen neuen datierten technischen Eintrag mit:
      - Ausgangslage
      - Ursachen
      - Änderungen
      - Messwerten
      - Screenshots/Trace-Pfaden
      - bestätigten Ergebnissen
      - verbleibenden Risiken

  12. CURRENT STATUS ganz oben wurde aktualisiert.

  13. HANDOFF.md enthält unter Last result:
      - Commit(s)
      - What was changed
      - Verified (built / tested / screenshots)
      - Deviations from the plan and why
      - Open questions for the planner

  14. Diff wurde kritisch geprüft.

  15. Alle Änderungen wurden committed und nach GitHub main gepusht.

  Falls Tests fehlschlagen, die Ergebnisse ausdrücklich als fehlgeschlagen dokumentieren. Keine unbelegte Fertigmeldung.

## Zusätzliche verbindliche Arbeitsanweisungen an Codex

1. Trage diesen Open task in HANDOFF.md ein. Ersetze den bisherigen Open task gemäß den Regeln am Dateianfang. Ältere Ergebnisse gegebenenfalls als kurze History-Zeile erhalten.

2. Prüfe alles gegen den lokalen Code. Übernimm keine Adresse, Registerannahme, Funktion oder Formel blind. Der echte Code hat immer Vorrang.

3. Ändere nur Dateien, die für die nachgewiesenen Probleme nötig sind.

4. Falls Änderungen in lib/ notwendig werden, erzeuge die entsprechende lib-patches/*.patch neu und prüfe, dass sie auf den gepinnten Submodulstand sauber anwendbar ist.

5. Baue mit build_jfg.bat und teste mit tools/test_60hz_gameplay.ps1. Werte Traces numerisch aus und erstelle Screenshots zu gleichen realen Zeitpunkten.

6. Schreibe einen datierten Eintrag in decomp/docs/RECOMP.md und aktualisiere CURRENT STATUS. Pflege ausschließlich diese Kopie im GitHub-Projekt, nicht die Datei im lokalen JFG_Decomp-Ordner.

7. Fülle Last result in HANDOFF.md vollständig aus. Kennzeichne Fakten, Annahmen, fehlgeschlagene Tests und verbleibende Probleme.

8. Prüfe vor dem Commit git diff und git status kritisch. Entferne versehentliche Debug-Ausgaben, temporäre Dateien und nicht benötigte Änderungen.

9. Committe und pushe die fertigen Änderungen nach main.

10. Committe niemals ROMs oder ROM-Ableitungen, insbesondere nicht RecompiledFuncs/, rsp/n_aspMain.cpp oder extrahiertes Microcode-Material.

11. Wenn 60 Hz noch nicht korrekt funktioniert, belasse die Option als Experimental und default OFF. Dokumentiere genau, welche Systeme noch fehlerhaft sind und welche Tests fehlen.

12. Die Priorität lautet: korrektes Spieltempo und Stabilität vor einer nominellen Updatefrequenz von 60 Hz.

Bitte den Auftrag eigenständig abarbeiten und das vollständige Ergebnis über HANDOFF.md und RECOMP.md im GitHub-Repo zurückmelden.

## Last result (Debug quick start, 2026-10-15)

- **Commit(s):** see the commit that contains this line (`git log -1`, message "Debug quick start ...").
- **What was changed:**
  - `src/main/main.cpp` `main()`: `--jfg-level <name>` (only `goldwood`; unknown name = error message and exit, no fallback);
    `--jfg-skip-intro` and `--jfg-skip-cutscenes` are accepted but print "not implemented yet, ignored".
  - `jfg_change_level()` (main.cpp), hooked on `mainChangeLevel` entry 0x8004665C via `decomp/recomp/jfg.us.toml`.
    With `--jfg-level`, the first character-select request (0x16D) is redirected to level 0x5D, char 1.
    Without the option: no change. `JFG_TRACE_LEVEL=1` logs every call.
  - `tools/test_debug_start.ps1` (new), runs the scripted title/menu route with the debug argument.
  - Local derived file `RecompiledFuncs/funcs_12.c`: the same hook line inserted by hand (not committed; a regeneration
    from `decomp/recomp/jfg.us.toml` must produce it again. Not regenerated in this task).
- **Verified (built / tested / screenshots):**
  - `build_jfg.bat build`: exit 0.
  - Default route, JFG_TRACE_LEVEL: level sequence 0x0, 0x15D, 0x7F, 0x16D(char 1)x5, 0x5D(char 1). 0x142 is NEVER called.
    So the NM_DIRECT_START idea (0x142 = new game) does not apply to this build's route.
  - `--jfg-level goldwood` run (runlogs/debug_start_goldwood_1.stderr.log): redirect at script ms 63334 (0x16D -> 0x5D,
    char 1), then 0x5C (Forest Day Landing) follows. Goldwood gameplay HUD and player visible at 116 s
    (runlogs/shot_1015_150803_116.png). Game still running at script end (no crash, one run only).
  - Default start regression (runlogs/default_start_regression.stderr.log): no redirect, 18 script steps, Goldwood
    at 116 s (runlogs/shot_1015_151401_116.png).
  - Not measured: the time to first controllable frame. Not repeated 10 times. Not tested with OFF->ON toggles.
- **Deviations from the plan and why:**
  - Level-id 0x15 from the earlier decomp notes ("Forest First") was NOT used. The route-verified level is 0x5D
    "Forest Day Sequence" (name table build/tmp/level_names.txt in the decomp project).
  - Redirect trigger is 0x16D (character select), not 0x142, because 0x142 is never called on the verified route.
  - Title and new-game menus are still driven by the scripted input. That is an intermediate solution, not a
    menu-free Direct Level Load. The main goal (menu-free start) is NOT achieved.
  - Intro skip and cutscene skip are NOT implemented (flags only print a message).
  - Savegames: test runs use the portable test folder build-cmake\run-jfg, not the user's own saves. Not checked
    file-by-file whether a new game writes a save slot there.
- **Open questions for the planner:**
  - Which game-state initialisation does new game perform before 0x16D, and can a menu-free start call mainChangeLevel
    (0x5D, char 1) directly after it? The old direct start from mainThread hung (NONMATCHING_BUILD.md:158).
  - Is char id 1 Juno (boy)? Inferred from the 0x16D "Boy Select" overlay name, not verified by a screenshot.
  - Intro and cutscene skip: which state variables end the logo sequence and the Goldwood landing (0x5C)?

## Previous Last result (60 Hz, paused)
_Partial. "Done when" is NOT met. Details in `decomp/docs/RECOMP.md` (entry 2026-10-15 afternoon)._

- **Commit(s):** one WIP commit "WIP: validate experimental 60 Hz gameplay" on `jfg/main` (the commit that contains this
  line; `git log -1`). Changed: `src/main/main.cpp`, `decomp/docs/RECOMP.md`, `HANDOFF.md`. Submodules (`lib/*`) were
  NOT committed: they still hold uncommitted changes; this commit does not cover them.
- **Teststand:** 60 Hz is still Experimental and default OFF. Not validated yet; see "Open" below.
- **What was changed:**
  - `jfg_gameplay_tick` (joyRead) now only writes `jfg_60hz_requested`.
  - `jfg_frame_sync_limit` (viFrameSync) is the only place that changes the active mode used by the scheduler hooks.
  - On enable it saves the three adaptive VI bytes (0x800FECAC/AB/AD); on disable it restores them, instead of a fixed 2.
- **Verified (built / tested / screenshots):**
  - Built: `build_jfg.bat build` exit 0.
  - Audit of scheduler hooks 0x800506E8 / 0x80050A58 and VI hook 0x80055104 against generated code: register and address correct.
  - A/B (`tools/test_60hz_gameplay.ps1`, 128 s): 60 Hz runs about 24 updates/s, same as 30 Hz (about 23.4/s). **Target of
    60 updates/s NOT reached on this machine.** Game timer equal in both modes (about 7640 VI ticks/128 s).
  - One 60 Hz run gave 13.7 updates/s; not reproduced, cause unknown.
  - Not done: OFF<->ON toggling, scene/pause changes, screenshot pairs, XYZ speed/jump/animation/camera/cutscene/audio/AI
    tests, input-latency (TEST 10), long-run tests (TEST 11), CURRENT STATUS update.
- **Deviations from the plan and why:** only the scheduler/VI part was addressed. The rest was not started, because the
  60 Hz bottleneck (render/present, not scheduler) has to be found first.
- **Second step (WIP, same branch, see `git log -2`):** loop timing added (`JFG_TRACE_LOOP=1`, env-gated, main.cpp).
  Five Goldwood runs (3 OFF, 2 ON) in RECOMP.md "late afternoon" entry. Result: ON and OFF show the same loop period in
  each state. B (viFrameSync wait) is quantised to VI periods; A (game + DL build) is about one VI in the fast state.
  Two states with the same exe (about 33 ms vs about 67 ms per iteration), cause unknown. Not yet split: game CPU vs
  blocking in osRecvMesg and RT64 processDisplayLists/present. That needs patches in lib/ (`lib-patches`), not done yet.
- **Open questions for the planner:**
  - What causes the fast/slow state switch with an unchanged binary? It decides whether any 60 Hz number is trustworthy.
  - Is 60 updates/s a realistic target on this hardware? Current data says the render/present path limits both modes to about 24/s.
  - Should the next step be profiling the render path, or should 60 Hz be dropped to a documented limitation?

## Questions / blockers
_(either side; delete when answered)_

## History
- 2026-10-15 13:00 Repo created; state: playable to Goldwood, mouse aim, optional mouse camera; 60 Hz gameplay checkbox in progress (Codex, 12:12).
