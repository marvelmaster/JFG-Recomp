"""Reproduce RT64's projective decomposition defect using its actual math.cpp.

Run in a Visual Studio developer environment, or use test_jfg_projective_matrix.bat.
This test intentionally asserts the current defect and separately checks that
the JFG no-decomposition/no-interpolation policy preserves all coefficients.
"""
from pathlib import Path
import os
import shutil
import subprocess

root = Path(__file__).resolve().parents[1]
build = root / 'build-cmake' / 'projective-matrix-tests'
build.mkdir(parents=True, exist_ok=True)
compiler = shutil.which('clang-cl') or shutil.which('cl')
if not compiler:
    raise SystemExit('Run from a Visual Studio developer environment with clang-cl or cl on PATH')
binary = build / 'jfg_projective_matrix_test.exe'
environment = os.environ.copy()
environment.update(TEMP=str(build), TMP=str(build))
subprocess.run([
    compiler, '/nologo', '/std:c++17', '/EHsc', '/MT',
    '/I' + str(root / 'lib/rt64/src'),
    '/I' + str(root / 'lib/rt64/src/contrib/hlslpp/include'),
    str(root / 'tests/jfg_projective_matrix_test.cpp'),
    str(root / 'lib/rt64/src/common/rt64_math.cpp'),
    '/Fe' + str(binary),
], cwd=build, env=environment, check=True)
subprocess.run([str(binary)], cwd=build, check=True, timeout=30)
