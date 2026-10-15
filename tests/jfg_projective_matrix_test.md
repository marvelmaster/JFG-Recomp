Run `test_jfg_projective_matrix.bat` from the repository root on Windows, or
`python tools/test_jfg_projective_matrix.py` in a Visual Studio developer shell.
Only the standalone test and actual RT64 `src/common/rt64_math.cpp` compile;
the renderer and game do not build or launch.

The test demonstrates a general defect in the currently pinned RT64 math code.
A projective row-vector matrix with translation X=2 and W column `(0,0,1,1)`
decomposes and recomposes to W column `(-2,0,1,-3)`. A sample point's X/W changes
from `3/2 = 1.5` to `3/-4 = -0.75`, including a positive-to-negative W change.

The second assertion uses actual RT64 component interpolation with decomposition
disabled and all components skipped, verifying that the JFG policy preserves
every original coefficient. This test does not apply any global RT64 fix.

The defect assertion intentionally expects the current incorrect result. If the
general RT64 bug is fixed upstream, replace that assertion with a correct
roundtrip assertion; the preservation-policy assertion should still pass.
