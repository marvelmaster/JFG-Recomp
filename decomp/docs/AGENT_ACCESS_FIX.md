# Access-type fix pass – agent guide

Project `F:\SelfmadeTools\JFG_Decomp`. Every decompiled function has C inside
`#ifdef NON_MATCHING ... #else #pragma GLOBAL_ASM(...) #endif`. The C must behave exactly like
the original asm. `tools/access_check.py` compared every function's loads/stores with the
original and found offsets where our C reads/writes with a **different width or type**, e.g.
`0x64: orig u8 vs C w` = the game reads a byte at +0x64 (lbu) but our C reads a 32-bit word.
These are real bugs in most cases (they already crashed the C-built ROM several times).

## Your task
For each listed function in your task file:
1. Read the C (in the given file) and the original asm `asm/nonmatchings/<...>/<func>.s`.
   Also run `.venv/Scripts/python.exe tools/match_func.py <file> <func>` for a side-by-side diff.
2. For each listed offset, find the access in the asm and make the C use the same type:
   lb→s8, lbu→u8, lh→s16, lhu→u16, lw→s32/u32/pointer, lwc1→f32 (a float **copy**, not an
   int→float conversion; `lw`+`mtc1`+`cvt.s.w` is the int→float case), sb/sh/sw/swc1 likewise.
   Fix struct field types in the file's own externs block if the field is declared wrong there.
3. Ignore a listed offset when it belongs to a different pointer/base in asm and C (false positive),
   but check carefully first.
4. Do not change behaviour otherwise, do not reformat, do not touch the `#else` pragmas, headers
   or other files. Use `.venv/Scripts/python.exe` (there is no `python3`).
5. Afterwards: `.venv/Scripts/python.exe tools/check_c.py <file>` and `... --asm <file>` must be OK.

## Report
`FIXED <file>: <func> (<offsets>) ...`, `FALSE POSITIVE <func> <offset> (reason)`, `CHECK: OK|FAIL <file>`.
