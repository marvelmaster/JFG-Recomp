"""Technical assertion for character meshes on a JFG_CAPTURE_DL capture (build-cmake/run-jfg/jfg_capture_<dl>,
jfg_commands_<dl>.txt): for every model (F3DJFG vertex base) all triangle corners must be projected by the GPU path
(RSPProcessCS output read back after the draw) with ONE common horizontal scale per viewport relative to RT64's CPU-side clip
position (widescreen aspect adjustment), and with the same y/w. Different scales inside one model = "sliced" model.
Usage: python tools/check_jfg_capture.py <dl> [run folder]. Exit 0 = PASS, 1 = FAIL, 2 = capture missing."""
import re
import sys
from collections import Counter
from pathlib import Path

import numpy as np

dl = sys.argv[1]
run = Path(sys.argv[2]) if len(sys.argv) > 2 else Path('build-cmake/run-jfg')
cap = run / f'jfg_capture_{dl}'
cmds = run / f'jfg_commands_{dl}.txt'
if not (cap / 'cpu_clip.bin').exists() or not (cap / 'after_draw_screen.bin').exists() or not cmds.exists():
    print('capture missing'); sys.exit(2)
clip = np.fromfile(cap / 'cpu_clip.bin', np.float32).reshape(-1, 4)
scr = np.fromfile(cap / 'after_draw_screen.bin', np.float32).reshape(-1, 4)
# Viewport of each vertex's projection (RSPViewport = scale.xyz, translate.xyz); screen = (x/w, -y/w) * scale + translate.
vps = np.fromfile(cap / 'after_draw_viewport.bin', np.float32).reshape(-1, 6)
vpi = np.fromfile(cap / 'after_draw_viewproj_indices.bin', np.uint16)
groups = {}
for line in cmds.read_text().splitlines():
    m = re.match(r'T face=\d+ draw=\d+ base=(\w+) .*global=([\d,]+)', line)
    if m:
        groups.setdefault(m[1], set()).update(map(int, m[2].split(',')))
# Split each model by viewport: different passes (off-screen targets, square viewports) legitimately use
# different aspect handling; inside one model and one viewport the scale must be one value.
split = {}
for base, gl in groups.items():
    for g in gl:
        split.setdefault((base, tuple(np.round(vps[vpi[g]], 2))), set()).add(g)
groups = {'%s vp=%s' % (b, '/'.join('%g' % x for x in v)): gl for (b, v), gl in split.items()}
fail = 0
for base, gl in sorted(groups.items()):
    scales, ybad = Counter(), 0
    for g in gl:
        c = clip[g]
        if abs(c[3]) < 1e-3:
            continue
        sx, sy, _, tx, ty, _ = vps[vpi[g]]
        # y compared in NDC (float precision near the camera, small w), w relative.
        if abs(-c[1] / c[3] - (scr[g][1] - ty) / sy) > 1e-3 or abs(c[3] - scr[g][3]) > 1e-4 * max(1.0, abs(c[3])):
            ybad += 1
        nx = c[0] / c[3]
        if abs(nx) < 0.05:
            continue
        scales[round(float(((scr[g][0] - tx) / sx) / nx), 3)] += 1
    ok = len(scales) <= 1 and ybad == 0
    fail |= not ok
    print('%s base=%s corners=%d x_scales=%s y/w_mismatch=%d' % ('PASS' if ok else 'FAIL', base, len(gl), dict(scales), ybad))
print('RESULT', 'FAIL' if fail else 'PASS')
sys.exit(1 if fail else 0)
