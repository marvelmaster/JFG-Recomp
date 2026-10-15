"""Summarise JFG_TRACE_LATENCY events in build-cmake/run-jfg/jfg_trace.log.
I = pad-1 input sampled by the game (osContGetReadData), D = display list handed to RT64, P = swap chain present.
For every input sample: time to the 1st and 2nd display list after it (the game builds the frame that uses the
input in one of them) and from that display list to the next present. Usage: python tools/latency.py [log] [from_s]"""
import sys, bisect, statistics as st
log = sys.argv[1] if len(sys.argv) > 1 else 'build-cmake/run-jfg/jfg_trace.log'
ev = {'I': [], 'D': [], 'P': []}
for line in open(log, errors='replace'):
    if line.startswith('LAT '):
        _, k, t = line.split()
        ev[k].append(int(t) / 1000.0)
t0 = min(v[0] for v in ev.values() if v)
start = t0 + (float(sys.argv[2]) * 1000 if len(sys.argv) > 2 else 0)
I = [t for t in ev['I'] if t >= start]; D = ev['D']; P = ev['P']
span = (I[-1] - I[0]) / 1000 if len(I) > 1 else 0
print(f"window {span:.1f}s: inputs/s {len(I)/span:.1f}  DLs/s {sum(1 for t in D if I[0] <= t <= I[-1])/span:.1f}  presents/s {sum(1 for t in P if I[0] <= t <= I[-1])/span:.1f}")
d1, d2, pres = [], [], []
for t in I:
    j = bisect.bisect_right(D, t)
    if j + 1 >= len(D): break
    d1.append(D[j] - t); d2.append(D[j + 1] - t)
    k = bisect.bisect_right(P, D[j])
    if k < len(P): pres.append(P[k] - D[j])
f = lambda a: f"mean {st.mean(a):.1f} ms  median {st.median(a):.1f}  max {max(a):.1f}"
print("input -> next DL      ", f(d1)); print("input -> 2nd DL       ", f(d2)); print("DL -> next present    ", f(pres))
gaps = [b - a for a, b in zip(I, I[1:])]
print("input sample interval ", f(gaps))
