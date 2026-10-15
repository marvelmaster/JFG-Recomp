"""Evaluate one 30/60 Hz A/B run of tools/test_60hz_ab.ps1 (JFG_TRACE_GAMEPLAY + JFG_TRACE_LEVEL trace).

All times are script milliseconds (JFG_INPUT_SCRIPT time base = wall clock from the first pad poll), so both modes are
compared per REAL second, not per update. Prints one JSON object with:
  updates_per_s, delta histogram, game timer VI ticks per real second  (steady window 1.5 s .. 10 s)
  walk_speed: horizontal distance per real second while UP is held (window --walk a,b in ms, default 2000,4000)
  jump_N: apex height above the take-off height, time to apex and airtime for each scripted jump (window -0.3..+1.5 s)
  scroll_calls_per_s: trackUpdateTextureScroll calls per real second (JFG_TRACE_SCROLL lines, if present)
  walk_response_ms / jump_N.response_ms: scripted press -> first update whose player state shows the effect
Usage: python tools/analyze_60hz.py <trace> [--walk 4500,6500] [--jumps 1000,2600]
"""
import collections
import json
import math
import re
import sys


def load(path):
    frames, order = {}, []
    scroll = []
    land = None
    for line in open(path, errors="replace"):
        m = re.match(r"JFG_GAMEPLAY frame=(\d+) ms=(\d+) on=(\d+) delta=(\d+) time=(-?\d+)", line)
        if m:
            f, ms, on, delta, t = map(int, m.groups())
            frames[f] = dict(ms=ms, on=on, delta=delta, time=t)
            order.append(f)
            continue
        m = re.match(r"JFG_PLAYER frame=(\d+) xyz=([-\d.]+),([-\d.]+),([-\d.]+)", line)
        if m and int(m[1]) in frames:
            frames[int(m[1])]["xyz"] = tuple(float(m[i]) for i in (2, 3, 4))
            continue
        m = re.match(r"JFG_LEVELINIT ms=(\d+) .*level=0x5C", line)
        if m and land is None:
            land = int(m[1])
            continue
        m = re.match(r"JFG_SCROLL ms=(\d+) run=(\d)", line)
        if m:
            scroll.append((int(m[1]), int(m[2])))
    return [frames[f] for f in order], land, scroll


def window(rows, a, b):
    return [r for r in rows if a <= r["ms"] < b]


def main():
    path = sys.argv[1]
    jumps = [1000, 2600]
    if "--jumps" in sys.argv:
        jumps = [int(x) for x in sys.argv[sys.argv.index("--jumps") + 1].split(",")]
    rows, land, scroll = load(path)
    out = {"trace": path, "land_0x5C_ms": land}
    steady = window(rows, 1500, 10000)
    if len(steady) > 2:
        span = (steady[-1]["ms"] - steady[0]["ms"]) / 1000.0
        out["updates_per_s"] = round((len(steady) - 1) / span, 2)
        out["delta_hist"] = dict(sorted(collections.Counter(r["delta"] for r in steady).items()))
        out["mode_on"] = sorted(set(r["on"] for r in steady))
        out["game_vi_per_s"] = round((steady[-1]["time"] - steady[0]["time"]) / span, 2)
        out["delta_sum_per_s"] = round(sum(r["delta"] for r in steady[1:]) / span, 2)
    wa, wb = 2000, 4000
    if "--walk" in sys.argv:
        wa, wb = (int(x) for x in sys.argv[sys.argv.index("--walk") + 1].split(","))
    walk = [r for r in window(rows, wa, wb) if "xyz" in r]
    if len(walk) > 2:
        a, b = walk[0], walk[-1]
        d = math.hypot(b["xyz"][0] - a["xyz"][0], b["xyz"][2] - a["xyz"][2])
        out["walk_speed_per_s"] = round(d / ((b["ms"] - a["ms"]) / 1000.0), 2)
    for n, t in enumerate(jumps, 1):
        seg = [r for r in window(rows, t - 300, t + 1500) if "xyz" in r]
        if len(seg) < 3:
            continue
        base = [r for r in seg if r["ms"] < t]
        y0 = base[-1]["xyz"][1] if base else seg[0]["xyz"][1]
        apex = max(seg, key=lambda r: r["xyz"][1])
        up = next((r for r in seg if r["ms"] >= t and r["xyz"][1] > y0 + 0.5), None)
        down = None
        if up:
            down = next((r for r in seg if r["ms"] > apex["ms"] and r["xyz"][1] <= y0 + 0.5), None)
        out["jump_%d" % n] = {
            "apex": round(apex["xyz"][1] - y0, 2),
            "takeoff_ms": up["ms"] if up else None,
            "apex_after_ms": (apex["ms"] - up["ms"]) if up else None,
            "airtime_ms": (down["ms"] - up["ms"]) if (up and down) else None,
        }
    # Reaction: first update at or after the scripted press whose player state shows the effect
    # (walk: horizontal move > 0.5 units from the position at the press; jump: y rises by > 0.5).
    if "--walk" in sys.argv:
        press = wa - 500 if "--walkpress" not in sys.argv else int(sys.argv[sys.argv.index("--walkpress") + 1])
        seg = [r for r in rows if r["ms"] >= press and "xyz" in r]
        if seg:
            p0 = seg[0]["xyz"]
            mv = next((r for r in seg if math.hypot(r["xyz"][0] - p0[0], r["xyz"][2] - p0[2]) > 0.5), None)
            out["walk_response_ms"] = (mv["ms"] - press) if mv else None
    for n, t in enumerate(jumps, 1):
        j = out.get("jump_%d" % n)
        if j and j.get("takeoff_ms"):
            j["response_ms"] = j["takeoff_ms"] - t
    if scroll:
        sw = [s for s in scroll if 1500 <= s[0] < 10000]
        if sw:
            span = (sw[-1][0] - sw[0][0]) / 1000.0 or 1
            out["scroll_calls_per_s"] = round(len(sw) / span, 2)
            out["scroll_applied_per_s"] = round(sum(1 for s in sw if s[1]) / span, 2)
    print(json.dumps(out))


if __name__ == "__main__":
    main()
