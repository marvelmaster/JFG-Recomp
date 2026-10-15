# Matching round – agent guide

Project: `F:\SelfmadeTools\JFG_Decomp` (Jet Force Gemini decomp). Every function already has
non-matching C inside `#ifdef NON_MATCHING ... #else #pragma GLOBAL_ASM(...) #endif`.
Your job: change that C so the IDO compiler produces **exactly** the original instructions.

## Rules

1. Edit only the `#ifdef NON_MATCHING` C bodies of the functions you were given, plus the
   file's existing `/* decomp: externs */` block (it is inside `#ifdef NON_MATCHING`).
   Never touch the `#else` pragma, never move blocks, never edit headers or other files.
2. The C must stay a faithful translation of the asm. Never make it match by writing
   something that behaves differently. No inline asm, no `register` tricks that change
   behaviour, no added helper functions.
3. Use the Windows tools only (Bash tool, Git Bash). Do not run `make` yourself and do not
   edit anything inside WSL; `tools/match_func.py` does the WSL part for you.
4. Temporary files only in `build/tmp`.

## Loop

```bash
.venv/Scripts/python.exe tools/match_func.py <src/file.c> <function>
```
- Prints `MATCH`, or `NO MATCH` with a table of the differing instructions
  (original on the left, your C on the right), or `COMPILE FAILED` with IDO's error.
- Edit the C, run it again. Up to ~15 attempts per function; then keep your best
  (still correct) version and move on.
- Also look at the original asm: `asm/nonmatchings/.../<function>.s`.
- After the last edit run both checks:
  `.venv/Scripts/python.exe tools/check_c.py <file>` and `... --asm <file>`.

## IDO 5.3 (-O2) matching hints

- **Stack frame size differs** (`addiu $sp,$sp,-0x..`): you have too many/few locals or a
  local whose address is taken. Remove temporaries the asm does not need; keep ones it spills.
- **Prologue stores `sw $a1,0x..($sp)`**: that argument is used after a call (or its address
  is taken). Mirror how the asm uses it.
- **lb vs lbu / lh vs lhu**: signedness of the type (s8/u8, s16/u16). `sll+sra 16` = s16 cast.
- **Instruction order / register choice**: change statement order, combine or split
  expressions, introduce or remove a temporary variable, swap `a + b` to `b + a`,
  use `x = y; if (x)` vs `if (y)`.
- **Loops**: try `for`, `while`, `do {} while` — IDO emits different branch layouts.
  Counter decremented in the branch delay slot usually means a `do {} while (--n)` form.
- **Float**: use `f` suffix on float literals (`1.0f`), `(f32)` casts where the asm has
  `cvt.s.w`; IDO loads float constants from .rodata.
- **Return value / void**: if the asm never sets `$v0`, the function is `void`.
- **`beql`/branch likely** appears for `-mips2` files only; don't fight it in -mips1 files.
- Empty-looking 7-line functions: usually `void f(args) {}` — the asm stores the args to
  the stack only because IDO -O2 does that for unused params of some types; check types.
- Pointer arithmetic: `*(s32 *)(p + 0x10)` with `u8 *p` gives the same code as a struct
  field; the choice rarely matters, but the *type* of the load does.

## Report (end of your final message)

```
RESULT <id>: <func>=match|nomatch [...]
CHECK: OK|FAIL <file>
```

## Compiler flags (src/libultra only)

Some `src/libultra/*.c` files were built with different IDO flags than `-O2`.
Typical signs: store before `jr $ra` with a `nop` in the delay slot, or locals kept on
the stack instead of `$s` registers. Try:
`tools/match_func.py <file> <func> --opt "-O2 -g3"` and `--opt "-O1"`.
If a function only matches with other flags, report it in the RESULT line as
`<func>=match(-O2 -g3)` – the lead adds the per-file flag to the Makefile.
Never change flags for files outside `src/libultra`.

## Proven tricks from earlier batches

- `s8`/`s16` parameters that cause a spurious `sw $aN` / `andi` → declare them `s32` (the store
  stays `sb`/`sh` because of the destination type).
- Frame too small/large → add or remove an unused local (`s32 pad;`, `char buf[0x10];`), keep
  declaration order.
- Shared return blocks in the asm → `goto ret0;` / `goto ret1;` labels.
- Address materialisation (`lui`+`addiu` vs separate `lui`) → use or drop a local base pointer
  `s32 *p = &GLOBAL;`.
- Reload a field from the argument (`*(u8 **)((u8 *)arg0 + 0x68)`) instead of caching it in a
  local when the asm reloads it.
- Asm with two `jr $ra; nop` pairs in one function = two functions merged by splat; report
  `nomatch` immediately, don't spend attempts.
- If you find a real decomp error while matching (wrong argument, wrong type), fix it – that is
  worth more than the match itself – and mention it in your report.
- **Wrong extern prototype** of a called function (too many/few args, f32 vs s32) is a frequent
  cause of frame-size and argument-register differences. Check each call's `$a0-$a3`/`$f12/$f14`
  and stack-arg setup in the asm and fix the prototype in the file's externs block. A function
  that takes no args but is called with leftovers can be declared unprototyped: `void f();`.
- Leaf function that stores an argument to its home slot (`sw $a0,0x0($sp)`) and reloads it:
  try an old-style (K&R) definition, e.g. `void f(idx) u8 idx; {` or a `u8`/`s16` param read
  back through its address – IDO spills promoted narrow params that way.
- Register numbers off by one or two everywhere (t6 vs t7, …) but identical instructions: try
  declaring/using temporaries in a different order or an extra unused expression is NOT
  allowed – after ~5 attempts report nomatch.
- **Decomp about 2x the original size, loop body repeated 4x** = IDO -O2 unrolled your loop but
  the original loop was not unrolled. Change the loop form so IDO cannot unroll it the same way:
  pointer walk instead of index, `while` with a `break`/early `return` inside, loop condition that
  depends on a value loaded inside the body, or `do {} while`. This is a structural fix worth
  trying before giving up on big size differences.
- `python3` does not exist on this machine; use `.venv/Scripts/python.exe` or the Edit tool.
