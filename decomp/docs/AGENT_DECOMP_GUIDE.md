# Decomp agent guide (Windows, non-matching)

Project root: `F:\SelfmadeTools\JFG_Decomp` (Jet Force Gemini, US ROM, IDO-compiled MIPS).
Use the Bash tool with POSIX syntax; always `cd /f/SelfmadeTools/JFG_Decomp` first.
Python: `.venv/Scripts/python.exe`. Never touch anything outside this folder.

## Goal
Replace each assigned `#pragma GLOBAL_ASM("asm/nonmatchings/.../FUNC.s")` with
readable, compilable C that does what the assembly does. Exact matching is NOT
possible here (no IDO compiler), so we produce **non-matching** C and keep the
asm as the build fallback.

## Steps per function
1. Draft: `.venv/Scripts/python.exe tools/m2c_func.py <src/file.c> <FUNC>`
   m2c_func.py already resolves runtime-linked `jal TrapDanglingJump` calls
   to the real overlay function name, so call that function normally.
   For overlay files it also applies the overlay relocation table, so calls and
   globals show real names (e.g. `Arctanf`, `D_overlay_3_0031A1D0`) instead of
   `func_0` / `D_0` placeholders. Never write calls to `func_0`.
   Overlay jump tables are rebuilt too, so `switch` statements decompile �
   a jump table is no longer a reason to skip.
   ALWAYS work from this m2c_func.py output: the raw overlay .s files still
   show `jal func_0` placeholders that only m2c_func.py resolves.
   (the raw asm is in `asm/nonmatchings/**/FUNC.s` if you need to double-check).
2. Clean the draft up:
   - Replace every `?` type and `M2C_ERROR(...)` with real C. Unknown struct
     fields: use an existing struct from `include/` if the offsets clearly fit,
     otherwise raw offsets like `*(s32 *)((u8 *)obj + 0x1C)`.
   - Unknown 4-byte params: `s32`; pointers: `void *` or a known struct ptr.
   - Keep `D_XXXXXXXX` / `func_XXXXXXXX` names unless the header already has a
     real name for that address.
   - KNOWN m2c BUG: loops whose counter is decremented in the branch delay
     slot (`bnez $t, loop` + `addiu $t, $t, -1` right after it) are often
     off by one in m2c's do/while. Count the iterations from the asm.
   - Simplify m2c noise (`temp_t8 = 6*4; x = 6; x = temp_t8;` -> `x = 24;`),
     turn goto-loops into `for`/`while` where obvious. Do not invent behaviour:
     no added NULL checks, clamps, early returns, or merging of different
     constants/branches, no new helper functions, no collapsing of unrolled
     loops (write them out as the asm does), no merging of repeated calls or
     conversions (if the asm calls Sinf twice or converts a value 3 times,
     write it that many times). If the asm reads garbage or does something odd,
     reproduce it and add a `/* asm: ... */` comment.
3. Missing declarations (externs for `D_...` globals, prototypes for called
   functions): add them near the top of the SAME .c file under a comment
   `/* decomp: externs */` (create it once, after the #includes). First grep
   `include/` and `src/*.h` – if a declaration already exists, use it as-is
   and do not redeclare it with a different type. **Do not edit headers.**
   If you CREATE the externs block, wrap it: `#ifdef NON_MATCHING` /
   `/* decomp: externs */` ... `#endif`, so the original asm build is not
   affected. Never add file-level `#include`s outside such a guard.
   If an existing header prototype conflicts with how the asm calls the
   function, do NOT skip: call it through a cast and add a short comment, e.g.
   `((void (*)(f32, f32, s32))mathOneFloatPY)(a, b, c); /* sig mismatch */`.
4. Replace the pragma line with exactly this block:

```c
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
<your C function>
#else
#pragma GLOBAL_ASM("asm/nonmatchings/.../FUNC.s")
#endif
```

5. After every 3-5 functions run the checker on the file:
   `.venv/Scripts/python.exe tools/check_c.py <src/file.c>`
   It must print `OK`. Fix your errors. At the end ALSO run
   `.venv/Scripts/python.exe tools/check_c.py --asm <src/file.c>` (original
   build without NON_MATCHING) � it must print `OK` as well. (If the file already failed before you
   touched it, only make sure you added no new errors.)

## Rules
- Never write calls to `TrapDanglingJump(...)` or `func_0(...)` � these are
  unresolved placeholders. If existing NON_MATCHING code in YOUR file still
  contains them, fix them too (re-run m2c_func.py for that function and use
  the resolved callee + real arguments). Report how many you fixed.
- Only edit the files and functions you were assigned. Exception: inside
  YOUR file you may fix prototypes and call sites in existing NON_MATCHING
  code when the asm proves the signature (e.g. a missing 4th argument). Other agents edit
  other files at the same time.
- Never delete existing human-written code. If the pragma already sits in an
  `#ifdef NON_EQUIVALENT` (or similar) block, keep that old code: rename its
  `#ifdef NON_EQUIVALENT` to `#if 0 /* old NON_EQUIVALENT attempt */` and put
  your NON_MATCHING block after its `#endif`.
- Never move a function: the NON_MATCHING block must replace the pragma at
  exactly its original position (function order in the asm build matters).
- Never delete a pragma without the `#ifdef NON_MATCHING ... #else` wrapper.
- Size alone is NOT a reason to skip: every function under ~400 asm lines
  must be attempted (count lines of its .s file). Only functions >= 400 lines
  may be skipped without an attempt.
- If a function cannot be made to pass the checker after 2 honest attempts
  (e.g. jump tables, hand-written asm, huge functions), leave its pragma
  untouched and list it as skipped.
- Temporary files (patch scripts, drafts) go ONLY into `build/tmp/` inside
  the project. Never write outside F:\SelfmadeTools\JFG_Decomp.
- Do not run splat, make, or git. Do not reformat unrelated code.
- Final answer: at most 5 lines:
  `DONE: <n>  SKIPPED: <names or none>  CHECK: OK|FAIL <file>`

## Reference material (READ-ONLY – never modify, never write there)
`%USERPROFILE%\Desktop\jfg hacking\JetForceGeminiRE\jfg-re` is a research
project (JFG Forge) that already decodes the game's data. Use it to name
struct fields and understand data formats instead of guessing:
- `docs/technical-notes.md` – model layout (texture records 8 B, groups 16 B,
  triangles 16 B, vertices 10 B, transforms 16 B, header +0x2D/+0x30/+0x4F/+0x54),
  animation assets 40–45, game timing (`phase += delayDat * scale`), weapons.
- `docs/models.md`, `docs/levels.md` (level object lists, placement records),
  `docs/audio.md`, `docs/textures.md`, `docs/characters.md`.
- `jfg_forge/core/*.py` – working parsers: `model_parser.py`, `animation_decode.py`,
  `level_objects.py`, `level_data.py`, `texture_formats.py`, `audio_sequence.py`,
  `prop_bank.py`, `matrices.py`. Their struct.unpack offsets = real field layouts.
- `research-results/*.json` – audits (sound callers, animation callers …).
Mention in a code comment when a name/layout comes from jfg-re.

## Big-function round (one function per agent)
You get exactly ONE large function (400–3000 asm lines). Skipping because of
size is NOT allowed in this round. Strategy:
1. Save the m2c draft to `build/tmp/<FUNC>.m2c.c` and work from that file.
2. Clean it up section by section (top to bottom). Big `switch`es and long
   if-chains are fine; keep `goto`s where m2c needs them rather than inventing
   structure. Keep it faithful (see rules above).
3. Every `?` type, `M2C_ERROR` and undefined `spXX`/`unksp` must be resolved:
   stack temporaries become locals; unknown struct accesses become raw offsets.
4. Insert it with the usual NON_MATCHING wrapper and run the checker
   (normal and --asm) until both print OK.
5. Only if it is truly impossible after a full attempt: leave the pragma and
   report `FAILED: <reason>`.
Final answer: `DONE: 1` or `FAILED: <reason>`, plus `CHECK: OK|FAIL <file>`.

### Diddy Kong Racing decomp (READ-ONLY reference, approved by the user)
`%USERPROFILE%\Desktop\jfg hacking\JetForceGeminiRE\research\diddy-kong-racing`
JFG is a heavily modified DKR engine, and that decomp is ~95% done in C.
Many JFG functions have a DKR twin with the same or a similar algorithm:
- JFG track.c ↔ DKR src/tracks.c · camera.c ↔ camera.c · particles.c ↔ particles.c
- lights.c ↔ lights.c · font.c ↔ font.c · menu.c ↔ menu.c · weather.c ↔ weather.c
- objects.c ↔ objects.c / object_functions.c / object_models.c
- rcpFast3d.c ↔ rcp_dkr.c · gameVi.c ↔ video.c · saves.c ↔ save_data.c
- textures.c ↔ textures_sprites.c · audio* ↔ audio.c / audiosfx.c / audio_spatial.c
- fx.c (wake/ripple) ↔ waves.c · main.c ↔ game.c / thread3_main.c
Find a twin by grepping DKR's src/ for the same constants, called library
functions or loop shape; also check DKR include/structs.h for struct layouts.
Use it to understand logic and pick names/types – but the JFG asm is the truth:
never copy DKR code that the JFG asm does not do. Mention "cf. DKR <func>" in a
comment when you used a twin. Never modify anything in that folder.
