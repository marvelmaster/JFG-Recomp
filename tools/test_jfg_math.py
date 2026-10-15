"""Compile actual generated Rare math/animation code and test known outputs.

Run in a Visual Studio developer environment: python tools/test_jfg_math.py
"""
import os
from pathlib import Path
import re
import shutil
import subprocess

root = Path(__file__).resolve().parents[1]
generated = root / 'RecompiledFuncs'
build = root / 'build-cmake' / 'math-tests'
build.mkdir(parents=True, exist_ok=True)
matches = [m[0] for source in generated.glob('funcs_*.c')
           for m in re.finditer(r'RECOMP_FUNC void matrixTranslate\(.*?(?=RECOMP_FUNC|\Z)', source.read_text(), re.S)]
assert len(matches) == 1, 'Regenerate RecompiledFuncs first'
(build / 'matrix_translate.inc').write_text(matches[0])
compiler = shutil.which('clang-cl')
if not compiler:
    raise SystemExit('Run from a Visual Studio developer environment with clang-cl on PATH')
binary = build / 'jfg_math_test.exe'
subprocess.run([compiler, '/nologo', '/O2', '/MT', '/DRECOMP_KSEG1_RDRAM',
               '/I' + str(root / 'lib/N64ModernRuntime/N64Recomp/include'),
               '/I' + str(generated), '/I' + str(build),
               str(root / 'tests/jfg_math_test.c'), '/Fe' + str(binary)], cwd=build, check=True)
subprocess.run([str(binary)], cwd=build, check=True, timeout=30)
