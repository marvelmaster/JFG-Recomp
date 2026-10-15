# JFG_Decomp – Projektstatus

Stand: 2026-10-08

## Ziel

1. Eine saubere Dekompilierung von Jet Force Gemini (US), zuerst lauffähig, dann möglichst matching.
2. Darauf aufbauend ein PC-Port, den man modden kann.

## Ausgangslage

- Basis ist das Community-Projekt aus `JetForceGeminiRE/research/Jet-Force-Gemini`, kopiert nach `F:\SelfmadeTools\JFG_Decomp`.
- ROM: `baseroms/baserom.us.z64`, SHA-1 `493ced9008dbe932d6e91179b68e8630cf23a023`.
- Referenzen werden nur gelesen, nie geändert:
  - `JetForceGeminiRE/jfg-re` mit jfg-forge (Modelle, Animationen, Sound)
  - `JetForceGeminiRE/research/diddy-kong-racing` (DKR-Decomp, gleiche Engine-Familie)

## Stand der Dekompilierung

- **2373 / 2373 Funktionen** (100 %) haben eine C-Version. Sie ist **non-matching**: noch nicht gegen die ROM verifiziert.
- Jede Funktion steht in diesem Muster:
  ```c
  #ifdef NON_MATCHING
  // decomp: m2c + cleanup, non-matching
  <C-Code>
  #else
  #pragma GLOBAL_ASM("asm/nonmatchings/.../func.s")
  #endif
  ```
  Ohne `NON_MATCHING` wird weiterhin exakt der Original-Asm gebaut.

Prüfungen:

- `tools/check_integrity.py <Originalprojekt>`: **257/257** Dateien behalten den Original-Asm-Build, in der richtigen Reihenfolge.
- `tools/check_c.py --all`: 255/257 OK. Die zwei Fehler gab es schon im Ausgangsprojekt:
  - `diCpuTraceCurrentStack.c` (`__$sp`)
  - `sched.c` (`taskID`)
- Offene Punkte (falsche Header-Offsets, Signatur-Konflikte, Stellen mit Asm-Abweichungen): siehe [REVIEW_NOTES.md](REVIEW_NOTES.md).

## Werkzeuge (`tools/`)

| Tool | Zweck |
|---|---|
| `m2c_func.py <datei.c> <func>` | m2c-Entwurf erzeugen. Löst Overlay-Relocations, `TrapDanglingJump` und Jump-Tables auf. |
| `overlay_relocs.py <n>` | Relocations eines Overlays statisch auflösen. |
| `check_c.py [--asm] [--all]` | clang-Syntaxcheck: mit `NON_MATCHING`, mit `--asm` ohne. |
| `check_integrity.py` | Prüft, ob die Reihenfolge der aktiven GLOBAL_ASM-Pragmas dem Original entspricht. |
| `fix_order.py` | Stellt die Original-Reihenfolge der Funktionsblöcke wieder her. |
| `guard_externs.py` | Packt Deklarationsblöcke in `#ifdef NON_MATCHING`. Ausnahmen: `saves.c` und `weather.c` bleiben ungeschützt. |
| `decomp_progress.py [--files]` | Fortschritt (asm vs. C). |
| `queue.py` | Batch-Verteilung an die Agenten. Zustand in `build/queue_state.json`. |

Agenten-Regeln: [AGENT_DECOMP_GUIDE.md](AGENT_DECOMP_GUIDE.md).

## ROM-Build (WSL)

Unter Windows scheitert IDO an den CRLF-Zeilenenden. `make` und die MIPS-binutils fehlen dort außerdem. Gebaut wird deshalb in WSL.

- Distribution: WSL Ubuntu 24.04. Vorhanden sind `make`, `python3`, `gcc`, `mips-linux-gnu-as` und `mips-linux-gnu-ld`.
- Arbeitskopie: `~/jfg` (= `~/jfg`) mit LF-Zeilenenden.
- IDO 5.3 (decompals/ido-static-recomp v1.2):
  - Linux: `~/jfg/tools/ido-recomp/linux`
  - Windows (Reserve): `tools/ido-recomp/windows`
- Test: `src/libultra/n_cspsetvol.c` kompiliert mit IDO in WSL.

Synchronisieren nach Änderungen im Windows-Ordner:

```bash
wsl -d Ubuntu -- bash -lc 'rsync -a --delete --exclude build --exclude .venv --exclude tools/ido-recomp /mnt/f/SelfmadeTools/JFG_Decomp/ ~/jfg/ && cd ~/jfg && find . -type f \( -name "*.c" -o -name "*.h" -o -name "*.s" -o -name "*.inc" -o -name "*.py" -o -name Makefile -o -name "*.ld" -o -name "*.yaml" -o -name "*.txt" \) -print0 | xargs -0 sed -i "s/\r$//"'
```

`--exclude tools/ido-recomp` sorgt dafür, dass der Linux-IDO in WSL erhalten bleibt.

## ROM-Build: Ergebnis (2026-10-09)

- `make` in WSL (`~/jfg`) baut die ROM: **SHA-1 identisch** mit `baserom.us.z64`.
- Nötige Korrekturen dafür:
  - `asm-processor` in WSL geklont (war ein leeres Submodul).
  - `tools/n64crc` mit gcc gebaut.
  - `n_synremoveplayer.c` auf `VERSION_kiosk` beschränkt (in der US-ROM gibt es die Funktion nicht).
  - `diprint.c`: Reihenfolge der rodata-Strings angepasst (splat hat `D_800AE454` in `vsprintf.s` migriert).
  - `overlay_135.c`: Hilfsfunktion und Deklarationsblock in `NON_MATCHING` eingeschlossen.
- Sync-Skript: `~/sync_jfg.sh` (Windows-Ordner nach `~/jfg`, CRLF wird zu LF, build/ und die Tools bleiben).

## Messung: Wie viel matcht schon?

- Messbuild in `~/jfg_nm`: `make -k DECOMP_MEASURE=1 CC_CHECK=true`.
  - Kompiliert den NON_MATCHING-Code mit exakt den Flags des Matching-Builds.
  - Der Link schlägt bewusst fehl, es zählen nur die Objektdateien.
- Vergleich: `tools/match_report.py <matching build> <measure build> --json out.json`.
  - Vergleicht Funktion für Funktion.
  - Bei Wörtern mit Relocation wird nur der Opcode verglichen.
  - Einschränkung: Ob das Ziel einer Relocation stimmt (richtiges Symbol), wird nicht geprüft.
- Gegenprobe: 459/463 schon vorher matchende C-Funktionen werden als matchend erkannt.
- **Ergebnis: 425 von 2369 dekompilierten Funktionen matchen bereits (17,9 %).**
- Der komplette NON_MATCHING-Code kompiliert mit IDO fehlerfrei. Dafür nötige Korrekturen:
  - void-Pointer-Arithmetik und Deklarationen mitten im Block in `overlay_3.c`, `overlay_4.c`, `overlay_68.c`, `overlay_135.c` und `track.c`.
  - `sched.c`: `taskID` ersetzt durch `unk6C`.
- Ein NON_MATCHING-*Link* scheitert noch an 2626 undefinierten Symbolen:
  - Hauptursache: Kurznamen wie `D_800A2ED0` statt der splat-Namen `D_800A2ED0_A3AD0`.
  - Dazu kommen Overlay-Daten-Symbole.
  - Lösung: eine Alias-Symboldatei plus Relocation-Erzeugung für Overlays.

## Nächste Schritte

1. Matching-Runde: Agenten arbeiten nicht-matchende Funktionen ab, geprüft mit `match_report.py`.
2. `REVIEW_NOTES.md` abarbeiten.
3. NON_MATCHING-Link: Symbol-Aliase anlegen und den Overlay-Build aus dem C-Code erzeugen. Danach ist eine spielbare ROM aus C möglich.
4. Structs und Namen aufräumen.
5. PC-Port, danach der UE5-Prototyp (Steuerung und Waffen).
