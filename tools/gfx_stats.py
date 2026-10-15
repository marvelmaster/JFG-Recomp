"""JFG_TRACE_GFX=1 statistics from a run log (stderr): per gfx task the queue wait S->B (submission until the gfx
thread starts send_dl), the send_dl time B->E, and the screen update (present) durations U. Usage: gfx_stats.py <log>"""
import re
import statistics
import sys

ev = []
for line in open(sys.argv[1], errors="replace"):
    m = re.match(r"JFG_GFX ([SBEU]) (-?\d+)(?: (-?\d+))?", line)
    if m:
        ev.append((m[1], int(m[2]), int(m[3]) if m[3] else None))
qs, ds, us = [], [], []
pend_s = []
cur_b = None
for k, t, d in ev:
    if k == "S":
        pend_s.append(t)
    elif k == "B":
        if pend_s:
            qs.append(t - pend_s.pop(0))
        cur_b = t
    elif k == "E" and cur_b is not None:
        ds.append(t - cur_b)
        cur_b = None
    elif k == "U":
        us.append(d)


def st(name, v):
    v = sorted(v[20:])
    if v:
        print("%s n=%d median=%.0f p10=%.0f p90=%.0f max=%.0f" % (name, len(v), statistics.median(v), v[len(v) // 10], v[len(v) * 9 // 10], v[-1]))


st("queue_wait_S_to_B_us", qs)
st("send_dl_B_to_E_us", ds)
st("screen_update_U_us", us)
