"""Median / p10 / p90 of the JFG_TRACE_LOOP intervals in a trace (A = joyRead -> viFrameSync entry, B = viFrameSync ->
next joyRead, W = wait inside rcpWaitDP, part of A). Skips the first N samples (boot). Usage: loop_stats.py <trace> [skip]"""
import re
import statistics
import sys

vals = {}
for line in open(sys.argv[1], errors="replace"):
    m = re.match(r"JFG_LOOP (\w)_us=(\d+)", line)
    if m:
        vals.setdefault(m[1], []).append(int(m[2]))
skip = int(sys.argv[2]) if len(sys.argv) > 2 else 30
for k in sorted(vals):
    v = sorted(vals[k][skip:])
    if v:
        print("%s n=%d median=%.0f p10=%.0f p90=%.0f" % (k, len(v), statistics.median(v), v[len(v) // 10], v[len(v) * 9 // 10]))
