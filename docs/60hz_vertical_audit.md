# Vertical physics audit

Baseline: `904acb2`, 2026-10-16. **[Code] only**: static inspection of decomp C and generated `RecompiledFuncs` instructions/operations. No runtime evidence, builds or physics changes. Scope is the seven common overlay gravity kernels, plus o16 jump wind-up; this is not an exhaustive audit of every collision/teleport/animation Y write.

## Common kernels [Code]

Fields: object `+0x10` Y, `+0x20` vertical velocity; state `+0x594` lift factor k. Gravity global is `0x800F6DC4`. Delta is in VI units. Each listed kernel applies gravity before its ordinary `objMoveXYZ` call (`0x80009A04`). Gravity subtraction is unconditional once the kernel is entered.

| Overlay/function suffix | ROM entry | Generated VRAM gravity subtract/store | Ordinary dy multiply | dy argument transfer |
|---|---|---|---|---|
| o15 `00F05ED4` | `01F19854` | `81F05F1C/81F05F20` | `81F06264`: f4=f8*f0 | add state358 at `81F0627C`, a2=f6 at `81F06284` |
| o16 `01005BB8` | `01F23BD0` | `82005C00/82005C04` | `82005F48`: f4=f8*f0 | a2=f4 at `82005F5C` |
| o17 `011050BC` | `01F2CC04` | `82105124/82105128` | `8210539C`: f6=f8*f0 | a2=f6 at `821053B0` |
| o50 `03201688` | `01F6B330` | `842016E4/842016E8` | `84201720`: f8=f4*f2 | a2=f8 at `8420172C` |
| o51 `0330134C` | `01F6DACC` | `843013A8/843013AC` | `843013E4`: f8=f4*f2 | a2=f8 at `843013F0` |
| o52 `03401688` | `01F700D0` | `844016E4/844016E8` | `84401720`: f8=f4*f2 | a2=f8 at `8440172C` |
| o53 `03501BB4` | `01F731E4` | `84501C00/84501C04` | `84501EA8`: f10=f6*f0 | a2=f10 at `84501EB8` |

In each dy multiply the first source is latest object velocity and second source is delta. o15/o16/o17/o53 apply `v -= (1-k)*g*d`; o50/o51/o52 apply `v -= g*d`. o15 additionally adds state358 to dy. Other kernels add state354/state35C to horizontal displacement where applicable. Further collision moves and velocity reconstruction occur after the ordinary move; these must not be confused with gravity integration.

Generated evidence: `funcs_36.c` (o15), `funcs_37.c` (o16), `funcs_38.c` (o17), `funcs_43.c` (o50-o53). Full function names are `func_overlay_<overlay>_<suffix>_<ROM-entry-without-leading-zero>`.

### o16 register lifetime and helpers [Code]

Immediately before `82005C00`: a0=obj, a1=state, s1=obj, s0=state, f6=old v, f4=`(1-k)*g*d`, f14=d. Subtraction produces f10=new v; `82005C04` stores it. At `82005F48`: s1=obj, s0=state, f8=latest v, f0=d. Gravity operands no longer reliably survive trig/helper calls. Capture applied acceleration at subtraction, associated with the object and current invocation, instead of relying on remaining FPRs or recomputing from potentially changed k.

No explicit obj20 store occurs in the o16 kernel between gravity store and main dy. However, st10D!=0 calls a dynamic helper at `82005ED4` (decomp identifies sidekickpadMovePlayer); st19F!=0 calls another at `82005F20` (transformerMovePlayer). Both are runtime-linked calls, so their runtime binding is not proven here.

The named helper bodies do affect vertical physics, verified against generated code:

- `sidekickpadMovePlayer`, o22, `funcs_39.c`: if object type 0x5D is found, damps obj20 at `82603098/826030A8`, blends state594 toward 1 at `826030C8`, then directly moves XYZ at `82603138` toward an oscillating target above that object.
- `transformerMovePlayer`, o129, `funcs_51.c`: if transformer lookup returns non-null, damps obj20 at `89100D3C/89100D4C`, blends state594 toward 1 or 0 according to transformer8C (`89100D78/89100D94`), may clamp velocity upward to its minimum at `89100E9C`, then directly moves XYZ at `89100EA0` toward an oscillating target.

An exact `latest_v == captured_v_new` guard rejects net intervening velocity changes, but is **not sufficient to prove unchanged vertical dynamics**: zero velocity can survive damping, rounding can hide changes, multiple changes can cancel, and either helper can alter Y or k independently. Conservatively exclude st10D/st19F helper modes, or explicitly track whether a helper ran, in addition to object/invocation matching and velocity equality. Equality is an extra guard, not a proof of safe correction.

### Other predicates [Code]

o15/o16 copy post-gravity v into state74, then skip pitch-related processing for state568 values 2 or 10. o17 adjusts heading when state568==5, then still applies gravity. These predicates do not disable the listed gravity subtract.

o53 is not a pure constant-acceleration kernel: after gravity, if v>2.5, it blends v toward 2.5 using Powerf and stores at `84501C78`, before ordinary dy. A correction based only on gravity must account for this modification or exclude it.

## o16 entry and wind-up [Code]

`boyControl`: VRAM `82000000`, ROM `01F1E018`. Its state568==3 jump-table case calls `01003464` at `82000BD0`; common gravity `01005BB8` is later called at `82000F88`.

Ground handler `01002708`, ROM `01F20720`, accepts jump press when `(controlModeKeys+C & controlDkeys)!=0 && state534==0`:

- state569!=0: countdown state57A=7, state57B=0 (`82002928/292C`).
- Otherwise moving `(abs(state4)>1.25 && stickMag!=0) || state56C!=0`: immediate v+=10 (`820029E0/29E4`), or 12 for multiplayer state189==7. If state510 is non-null, subtract that platform's vertical velocity (`82002A04/2A08`).
- Otherwise standing: countdown state57A=24, state57B=0 (`82002A28/2A2C`).
- Sets state568=3 (`82002A50`), clears state58E and records Y into state57C.

Jump-state handler `01003464`, ROM `01F2147C`:

- Landing/move predicate `(state360[5] & state532)!=0 && signed(state57A)==0` takes an earlier branch restoring state568 from state56A and clearing lift flags.
- With signed state57A>0, subtract truncated delta (`820036A4/36A8`). Held jump `(controlModeKeys+C & controlKeys)!=0` increments unsigned state57B by delta (`820036C8..36D8`); release clears countdown (`820036DC`).
- When countdown<=0, state569!=0 adds 10 (`82003748/3750`). Otherwise clamp hold count to 24; add `6+(12-6)*hold/24` at `820037EC`, store at `820037F0`. Multiplayer state189==7 substitutes upper endpoint 15.
- Therefore hold6 produces a 7.5 impulse; hold8 produces 8.0. These are additions to existing velocity, followed by same-update gravity. **No claim that a particular measured jump used either hold count:** that requires tracing.
- Later airborne branches can damp velocity, blend toward v=5, and vary k for jet/lift inputs; constant gravity must not be assumed there.

## Juno selection limit [Code]

Generated controlPlayer (`funcs_7.c`) tests stateFC at `80032FD8`. FC==0, state[1] cases0/4 select call `80033090`, identified by decomp as boyControl. FC!=0, cases0/4 select `8003301C`, identified as boyBossControl. Generated call targets are runtime-linked TrapDanglingJump sites; static generated code alone does not prove their live binding. `src/main/main.cpp` identifies fast-start menu character parameter1 as Juno, but this parameter must not be equated with state[1]. Confirm o16 entry with runtime instrumentation before claiming which route the tested Juno used.

## Correction boundary [Code]

`decomp/docs/RECOMP.md` late-night 60 Hz entry proposes changing only dy to `(v-(1-k)*g*(2-d)/2)*d`, preserving velocity evolution, for the constant-acceleration semi-implicit kernel. It does not establish correctness across impulses, variable k, helper motion, clamps, collision transitions, or o53's soft limit. This audit supplies hook locations; it supplies no runtime equivalence proof.
