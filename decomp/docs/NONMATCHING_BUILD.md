# Spielbare ROM aus dem C-Code (NON_MATCHING-Build) – Plan

Stand 2026-10-09. Ziel: eine ROM, deren Code komplett aus unserem C kommt (`make NON_MATCHING=1`)
und die im Emulator läuft. Damit wird die Dekompilierung funktional geprüft – Voraussetzung für
den PC-Port.

## Ausgangslage

- Der Matching-Build (`make`) erzeugt die Original-ROM (SHA-1 OK). Er nutzt den Original-Asm und
  die aus der ROM extrahierten Binärtabellen.
- Der C-Code kompiliert vollständig mit IDO (`make DECOMP_MEASURE=1`), linkt aber noch nicht.
- Sobald sich Funktionsgrößen ändern, verschieben sich alle Adressen dahinter. Die ROM enthält
  aber mehrere Tabellen mit festen Adressen/Offsets. Diese müssen neu erzeugt werden.

## Probleme und Lösungen

### 1. Symbolnamen (2626 undefinierte Symbole)
- Der C-Code nutzt Kurznamen (`D_800A2ED0`), splat definiert `D_800A2ED0_A3AD0`.
  → Alias-Datei erzeugen: jeder Kurzname = splat-Symbol an derselben Adresse
  (aus `mips-linux-gnu-nm build/jfg.us.elf`).
- Overlay-Variablen (`D_overlay_N_XXXXXXXX`) liegen oft im BSS des Overlays (Adresse = Ende von
  text+data, dort liegt in der ROM die Reloc-Tabelle). → pro Overlay BSS-Symbole definieren
  (Linker-Symboldatei relativ zu `overlay_N_bss_VRAM`), Daten-Symbole auf die splat-Namen aliasen.
- Falsch benannte Symbole (aus m2c-Relocation-Raten) fallen dabei auf und werden korrigiert.

### 2. Hauptcode verschiebbar machen
- `mainRelocTable.bin`: Liste der Stellen im Hauptcode, die zur Laufzeit auf Overlay-Funktionen
  gepatcht werden (`TrapDanglingJump`). Offsets ändern sich → aus den ELF-Relocations neu
  erzeugen (Aufrufe auf Overlay-Symbole).
- `overlayRomTable.bin` (ORT): Index → (Besitzer, Offset). Einträge für Besitzer 0 (Hauptcode)
  und die Daten/BSS-Bereiche ändern sich → Index→Symbolname aus der Original-ROM bestimmen und
  mit den neuen Adressen neu schreiben.
- Asm-Datendateien müssen alle Zeiger symbolisch enthalten (splat macht das meist; prüfen).

### 3. Overlays
- In der ROM stehen externe Zugriffe als Platzhalter (`jal 0`, `lui 0`) + Reloc-Tabelle, die
  `runLink.c` zur Laufzeit patcht (Typen 0 extern über ORT, 1 lokal, 2 Sprung, 3 Daten; Patch
  4=JAL, 5=HI16+LO16, 6=LO16, 2=Wort; Addend steht im Befehl).
- Für C-Overlays: jedes Overlay mit Relocations linken (`--emit-relocs`), dann ein Nachbearbeitungs-
  schritt: externe Ziele → ORT-Index, Platzhalter auf 0 bzw. Addend setzen, Reloc-Tabelle im
  Rare-Format schreiben (Grundlage: `tools/overlay_reloc.py generate`, `tools/overlay_linker.py`).
- Overlay-Tabelle (ROM 0x1ED2780: vram, rom-offset, text/data/bss-Größen, Reloc-Größen,
  init/resume) mit den neuen Größen neu schreiben.

## Reihenfolge

1. Alias-/BSS-Symboldateien erzeugen → Link läuft durch.
2. Hauptcode aus C, Overlays weiter aus Original-Asm (Overlay-Bytes unverändert): mainRelocTable
   + ORT neu erzeugen → ROM im Emulator testen.
3. Overlays aus C, Overlay für Overlay (zuerst kleine), mit Reloc-Generator → jeweils testen.
4. Alles aus C.

Bei Fehlern im Emulator lässt sich so immer eingrenzen, welche Datei/welches Overlay schuld ist:
Datei für Datei zwischen C und Asm umschalten.

## Fortschritt (2026-10-09)

- `tools/gen_nm_aliases.py` erzeugt `ver/symbols/nonmatching_aliases.us.txt` (2632 Aliase:
  Kurznamen, Overlay-Daten mit Offset, Overlay-BSS relativ zu `overlay_N_BSS_START`,
  KSEG0-Overlay-Adressen). Das Makefile bindet sie bei `DECOMP_MEASURE=1` ein.
- Der Link im Messbuild scheitert danach nur noch an 8 Symbolen + 1 Doppeldefinition:
  - `D_1000A0838`, `D_1000F2D58`, `D_1000F2E58`: m2c-Rechenfehler, gemeint ist die
    physische Adresse (`NullTextureOffsets`/`swpolygons` + 0x80000000, 32-Bit-Überlauf).
  - `pausePlayer` (o19), `pausetunevol` (o12): Overlay-übergreifende Daten → Alias über
    `ver/symbols/overlays.us.txt`.
  - `gDelayedSounds`, `D_FFC00300`: Adresse aus dem Asm bestimmen.
  - `func_overlay_3430_D6600000` (weather.c, 0x8005C158): ORT-Index 1747 = 0xD6600000 – ungültiger
    Eintrag; Bedeutung klären.
  - `gRetraceCounter64` doppelt (sched.c C + asm/data/sched.data.s).
- **Wichtig:** Aufrufe vom Hauptcode in Overlays stehen im C als direkte Funktionsaufrufe. Der
  Linker würde sie auf die Overlay-VRAM legen, zur Laufzeit liegen Overlays aber woanders. Für
  eine laufende ROM muss der Link-Nachbearbeitungsschritt diese Aufrufe wieder auf
  `TrapDanglingJump` + `mainRelocTable`-Eintrag umbauen (Schritt 2 oben). Genauso Overlay→Overlay.

## Schritt 2 umgesetzt (2026-10-09)

Bauen (WSL):
```bash
~/sync_nm.sh            # Windows-Ordner -> ~/jfg -> ~/jfg_nm
cd ~/jfg && .venv/bin/python3 tools/gen_nm_aliases.py build/jfg.us.elf ~/jfg_nm/build ~/jfg_nm/ver/symbols/nonmatching_aliases.us.txt
cd ~/jfg_nm && make -j16 DECOMP_MEASURE=1 CC_CHECK=true NM_SCOPE=main
cp build/jfg.us.z64 build/jfg_nm_main.z64
~/jfg/.venv/bin/python3 tools/nm_postlink.py ~/jfg/build/jfg.us.elf build/jfg.us.elf build/jfg_nm_main.z64 tools/nm_manual_ort.txt
~/jfg/tools/n64crc build/jfg_nm_main.z64
```
- `NM_SCOPE=main`: Overlays bleiben Asm (`-UNON_MATCHING` für `src/overlays`).
- Linkerskript-Kopie `build/jfg.us.nm.ld` füllt den Hauptcode auf seine Original-ROM-Größe
  (0xB1750) auf → Assets/Overlays bleiben an ihren Original-ROM-Adressen.
- `--noinhibit-exec`: die `jal`s vom Hauptcode in Overlays sind nicht linkbar (anderes 256-MB-
  Segment); `tools/nm_postlink.py` macht daraus wieder `jal TrapDanglingJump` und schreibt
  `mainRelocTable` (503 Einträge) + ORT (1573 Hauptcode/Daten/BSS-Einträge neu).
- Aufrufe mit Signatur-Cast auf Overlay-Funktionen erzeugen indirekte Aufrufe (lui/addiu/jalr)
  → stattdessen Alias-Namen (`cloneSetupShadow_2arg` usw., `ver/symbols/nonmatching_manual.us.txt`).
- Ergebnis: ROM `build/jfg_nm_main.z64`; nach dem Hauptcode identisch mit dem Original bis auf
  die zwei Tabellen. **Test im Emulator steht aus.**

## Automatischer Test + erste Fehler gefunden (2026-10-09)

Werkzeuge (WSL):
- mupen64plus ohne Root in `~/m64/root` entpackt (apt-get download + dpkg -x).
- `tools/m64probe.py` / `tools/probe_rom.sh`: ROM headless laufen lassen, PC/Register/RAM ausgeben.
  Erfolgskriterium: `mainGameMode` (Symbol) erreicht 6 wie beim Original.
- `tools/nm_build.sh <out.z64> [asm-Dateien]`, `tools/nm_test.sh <name> [asm-Dateien]`,
  `tools/nm_bisect.py` (Datei-Bisektion), `tools/nm_func_bisect.py` (Funktions-Bisektion).

Gefundene und behobene Ursachen:
1. Werkzeugkette: Original-Einträge der mainRelocTable in unveränderten Funktionen fehlten;
   Tabellen wurden über mehrdeutige Asset-VMAs geschrieben (jetzt `*_ROM_START`).
2. **Absolute Symbole aus den splat-Dateien** (`undefined_syms*.txt`) überschreiben im Linker
   Objekt-Definitionen und bleiben fest, wenn Code/Daten wandern (z. B. `gzip_cplext`,
   `D_1FEB040`). `tools/nm_filter_syms.py` erzeugt verschiebbare Versionen in `build/nm_syms/`.
   Danach ist die ROM verschiebbar (Hauptcode darf wachsen/schrumpfen, Assets wandern mit).
3. C-Fehler:
   - `gsSnd.c` gsSndpNew: Soundstates sind 0x48 Bytes (nicht sizeof(ALSoundState)), `numGroups` ist u16.
   - `include/PR/n_libaudio.h`: N_ALCSPlayer/N_ALSeqPlayer 4 Bytes Lücke vor `frameTime` ergänzt
     (Matching-Build bleibt identisch).
   - `n_event.c`: Events werden mit `bcopy(…, 0x10)` kopiert (JFG-Eventgröße), nicht per Struct-Zuweisung.
- Ergebnis: **Hauptcode komplett aus C erreicht im Emulator denselben Spielzustand wie das
  Original** (`build/jfg_nm_main.z64`, 30 s stabil). Overlays sind noch Original-Asm.

## Stand 2026-10-09 abends: echter Bildtest

- `mainGameMode == 6` war ein zu schwaches Kriterium (wird sofort im Boot gesetzt).
- Neu: `tools/rom_shots.sh` lässt die ROM mit Grafik (rice-Plugin über WSLg/llvmpipe) laufen und
  speichert Screenshots bei bestimmten Frames. Original: Frame 300 = Rareware-Logo.
  `tools/nm_test.sh` gilt als GOOD, wenn Frame 1200 erreicht wird. Gegenproben: alles-Asm GOOD,
  Code-Verschiebung GOOD, Wachstum des Hauptcodes GOOD.
- Mit diesem Test gefundene/behobene C-Fehler: `animseqCamera` (Float-Kopie statt Int->Float),
  `fxInit` (Schreibziel D_800A67A8). Hauptcode komplett aus C erreicht Frame 300 noch nicht →
  weiter bisektieren:
  ```bash
  wsl -d Ubuntu -- bash /mnt/f/SelfmadeTools/JFG_Decomp/build/tmp/bis_all.sh      # Datei finden
  # dann tools/nm_func_bisect.py src/<datei>.c <alle anderen Dateien> (siehe build/tmp/fb.sh)
  ```
- Direktstart-Option vorbereitet: `NM_START_LEVEL=0x15 NM_START_CHAR=1 bash tools/nm_build.sh out.z64`
  (main.c, `NM_DIRECT_START`). Level-Namen: build/tmp/level_names.txt (0x015 = "Forest First").
  Welche Zahl Vela ist, ist noch nicht bestätigt.

## 2026-10-10: Zugriffs-Prüfung
- `tools/access_check.py <matching build> <measure build> --json out.json`: findet Funktionen, deren
  Lade/Speicher-Befehle (ohne $sp, ohne Relocations) an einem Offset andere Breite/Typ haben als das
  Original. 526 Treffer (179 Hauptcode, 347 Overlays). Messbuild dafür: `~/jfg_nm2` (alles C, `make -k
  DECOMP_MEASURE=1 CC_CHECK=true`), siehe build/tmp/acc.sh.
- 6 Sonnet-Agenten haben alle Hauptcode-Treffer abgearbeitet (Anleitung docs/AGENT_ACCESS_FIX.md,
  Aufgaben build/tmp/acc_tasks/main*.txt). Viele echte Fehler korrigiert, Fehlalarme begründet.
- Hauptcode komplett aus C bootet danach immer noch nicht (Bildtest) → nächste Bisektion:
  `wsl -d Ubuntu -- bash /mnt/f/SelfmadeTools/JFG_Decomp/build/tmp/bis_all.sh`
- Offen: Overlay-Treffer (347) mit Agenten abarbeiten (vor Schritt 3).

### 2026-10-10
- objects.c: `RomTab`, `objdefno`, `objdeflist` are pointer *variables* in the game (asm does `lw %lo(sym)`), were declared as arrays -> objGetObjdef/objFreeObjdef indexed the pointer's own storage. Fixed declarations.
- New tool `tools/symuse_check.py <matching build> <measure build>`: lists symbols the original only loads (`lw`) while our C takes their address (`addiu`). Many false positives (IDO address materialization, indexed array loads `lw %lo(sym)(base)`); check the declaration by hand.
- Full-C main ROM still BAD after this fix; next file bisect log: build/tmp/bis_all6.log.
- particles.c func_8005D930 (partFreeLib helper): graphic-id list from piRomLoad(0x3C) is s16 (lh, stride 2); C read u32 with stride 8. Fixed. Full-C still BAD -> bisect log build/tmp/bis_all7.log.
- track.c func_8001412C + trackLightFreeMem: m2c loop bug (see REVIEW_NOTES "while (n--)"). Fixed.
- libultra n_load.c n_alLoadParam: `bcopy(loop->state, lstate, 0x20)` - +0x10 is the lstate *pointer*; C copied into the filter struct itself (clobbered loop/table fields). Fixed.
- **RESULT 2026-10-10: main code all-C ROM reaches frame 1200 (title screen).** Copy: build/jfg_allC_main.z64 (overlays still asm). Matching build SHA-1 still OK.
- Direct start: booting straight into a level from mainThread hangs (also with asm main code), so the old hack was removed. New hack (NM_DIRECT_START, src/main.c mainChangeLevel): normal boot/title; choosing "new game" (level 0x142 = ship intro) is redirected to NM_START_LEVEL/NM_START_CHAR. Build: build/jfg_allC_vela_goldwood.z64 (0x15, char 1 - char id for Vela unverified; boots to title, menu path untested headless).

### Step 3 design (overlays from C) - 2026-10-10
Runtime facts (src/runLink.c): overlay N in ROM = text | data | reloc table (RelocationTableSize) [| secondary table]. OverlayHeader (ROM 0x1ED2780, 0x20 bytes/entry, index N-1... check):
VramBase(0) RomAddress TextSize DataSize RodataSize(=BSS size) u16 RelocSize u16 SecondarySize InitFunction ResumeFunction (offsets, -1 = none).
Reloc entry = (u32 sym, u32 info): type = info&15, flagsHi = (info>>4)&15 (2 word, 4 jal, 5 hi + following lo entry, 6 lo), offset = info>>8 relative to text base (offset >= TextSize patches data).
type 0: sym = ORT index (main/other overlay). type 1: sym = offset in own overlay (flagsHi 2: + existing word). type 2: own jal (target from instruction). type 3: patch in data section, ORT target (cross-update loop re-processes types 0 and 3).
Generator plan (tools/nm_ovl_postlink.py, not written yet):
1. NM ld script: move `overlay_N_reloc.bin.o(.data)` after `.rodata` (C rodata must be part of the data size, the table last).
2. Link with --emit-relocs; for every reloc in .overlay_N: target inside overlay -> type 1 (R_MIPS_26 -> type 2), else type 0 with ORT index (data patches -> type 3).
3. ORT: remap overlay-owned entries via symbol names (orig ELF addr -> name -> NM ELF addr); append entries for new targets if the table has room.
4. Write new overlay_N_reloc.bin (sizes only depend on the overlay itself), relink (pass 2), regenerate overlay table (RomAddress, sizes, init/resume offsets via symbols).
5. Bring overlays over one at a time (small ones first), screenshot test each; NM_SCOPE needs a per-overlay C list.
- 2026-10-10 midday: user reported crash in PJ64 -> all-C ROM crashed after the title (attract 3D scene, frame ~2400). tools/nm_test.sh criterion is now frame 3600 (200 s).
  Cause: include/PR/libaudio.h ALSeqpConfig had the DKR-only `u8 unknown_0x10` (RAREDIFFS); JFG reads initOsc at 0x10 -> n_alCSPNew stored wrong osc callbacks. Field removed (matching SHA unchanged).
  tools/nm_func_bisect.py now handles 2-function interactions. NOTE: its extra args are files kept on ASM (fb.sh passes all others -> they are asm!).
  Full-C main ROM GOOD at frame 3600; ROMs refreshed: build/jfg_allC_main.z64, build/jfg_allC_vela_goldwood.z64.
- 2026-10-10 afternoon: Project64 "fatal error after Rare logo" = PJ64 picks settings by header CRC -> `bash tools/pj64_register.sh <roms>` (Git Bash, PJ64 closed) copies the original RDB entry. With that the all-C ROM reaches the save select in PJ64, then "Unhandled opcode".
- Headless input: `NM_AUTO_INPUT=1` (src/controller.c) scripts pad 1: START/A taps, then walks the name-entry keyboard to END -> original code reaches the ship intro (frame ~4800) without a human.
  Test: `NM_AUTO_INPUT=1 NM_TEST_FRAMES=1200,5400 NM_TEST_SECS=280 bash tools/nm_test.sh <name> [asm files]`; picture series: build/tmp/auto.sh <name> <main|none>.
  All-C: front-end 3D objects (keyboard/frame) are not drawn and it hangs after name entry -> bisect log build/tmp/bisA.log.
- Unexplained: at 15:18 audio_manager_1050.c/textures.c got duplicated tokens (`u16 bite;` twice, `*(u16 *) &*(u16 *) &`); reverted. If it reappears, look for a non-idempotent script.
- Test reliability lessons (2026-10-10): (1) mupen keeps saves per ROM hash in ~/.local/share/mupen64plus/save -> an identical ROM rebuilt later starts with the save of the earlier run; tools/rom_shots.sh now wipes them. (2) long runs are timing-flaky; fast criterion: `NM_AUTO_INPUT=1 NM_TEST_FRAMES=1200 NM_TEST_SECS=120 NM_TEST_MINSIZE=40000` (name-entry screen PNG is ~94 KB with its 3D objects, ~2 KB without).
- menu.c setupFrontEndObject: copied 5 floats as `(f32) *(s32 *)` (int->float) instead of float copy -> front-end objects invisible. camera.c camDoSprite/camDo2DSprite: vertex coords are `(s16)(s32)*(f32 *)` (cvt.w.s), C read the raw bits. Fixed.
- tools/access_check.py now also compares LOAD kinds separately ("load orig f32 vs C w") - catches these even when a store of the other kind exists at the same offset. 11 such hits remain in overlays.
- 2026-10-10 late: objects.c objLoadObjList fixed (ROM table stride 4, C used 8). All-C ROM still hangs loading the intro after name entry;
  file bisect again -> objects.c, function bisect (build/tmp/fb_obj4.log) aborted for shutdown: both 19-function halves GOOD alone
  -> two functions interact. Resume with `bash build/tmp/fb_o2.sh` (nothing else may build in ~/jfg_nm meanwhile).
  Strategy from here: see docs/RECOMP.md (Windows build via N64Recomp) - bisect only for specific bugs.
