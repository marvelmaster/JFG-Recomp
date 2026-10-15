"""Per-frame timeline from JFG_TRACE_LOOP (jfg_trace.log) + JFG_TRACE_GFX (run log, stderr), same steady clock (us).
For each main-loop iteration: viFrameSync entry (V, the DL of this frame is handed over around here), the next gfx
task submission S and its send_dl end E (runtime DP done), and the end of the next rcpWaitDP wait (R = the game gets
the done message). Prints medians of S-V, E-S, R-E. Usage: frame_timeline.py <trace> <runlog>"""
import bisect
import re
import statistics
import sys

V, R = [], []
for line in open(sys.argv[1], errors="replace"):
    m = re.match(r"JFG_LOOP A_us=\d+ on=\d t=(\d+)", line)
    if m:
        V.append(int(m[1]))
    m = re.match(r"JFG_LOOP W_us=\d+ t=(\d+)", line)
    if m:
        R.append(int(m[1]))
S, E = [], []
for line in open(sys.argv[2], errors="replace"):
    m = re.match(r"JFG_GFX ([SE]) (\d+)", line)
    if m:
        (S if m[1] == "S" else E).append(int(m[2]))
rows = []
for v in V[30:-2]:
    i = bisect.bisect_left(S, v)
    if i >= len(S):
        break
    s = S[i]
    j = bisect.bisect_left(E, s)
    k = bisect.bisect_left(R, s)
    if j >= len(E) or k >= len(R):
        break
    rows.append((s - v, E[j] - s, R[k] - E[j]))
for name, idx in (("S-V submit after viFrameSync entry", 0), ("E-S runtime processing", 1), ("R-E done -> game receives", 2)):
    vals = sorted(r[idx] for r in rows)
    print("%-38s n=%d median=%.0f p10=%.0f p90=%.0f" % (name, len(vals), statistics.median(vals), vals[len(vals) // 10], vals[len(vals) * 9 // 10]))
