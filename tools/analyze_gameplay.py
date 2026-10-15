"""Summarize JFG_TRACE_GAMEPLAY logs in script-time windows (milliseconds)."""
import collections
import json
import math
from pathlib import Path
import re
import sys


def analyze(path):
    frames = {}
    for line in Path(path).read_text(errors="replace").splitlines():
        match = re.match(r"JFG_GAMEPLAY frame=(\d+) ms=(\d+) on=(\d+) delta=(\d+) time=(\d+)", line)
        if match:
            frame, ms, on, delta, time = map(int, match.groups())
            frames[frame] = dict(ms=ms, on=on, delta=delta, time=time)
        match = re.match(r"JFG_PLAYER frame=(\d+) xyz=([\d.,-]+)", line)
        if match and int(match[1]) in frames:
            frames[int(match[1])]["xyz"] = list(map(float, match[2].split(",")))
    results = {}
    for start, end in [(10000, 20000), (105000, 110000), (110000, 113000), (116000, 119000), (120000, 126000)]:
        rows = [v for v in frames.values() if start <= v["ms"] < end]
        if len(rows) < 2:
            continue
        elapsed = (rows[-1]["ms"] - rows[0]["ms"]) / 1000
        result = dict(updates_per_second=(len(rows)-1)/elapsed,
                      game_ticks_per_second=(rows[-1]["time"]-rows[0]["time"])/elapsed,
                      deltas=dict(collections.Counter(v["delta"] for v in rows)))
        positions = [v["xyz"] for v in rows if "xyz" in v]
        if positions:
            result.update(first_xyz=positions[0], last_xyz=positions[-1],
                          displacement=math.dist(positions[0], positions[-1]),
                          min_y=min(p[1] for p in positions), max_y=max(p[1] for p in positions))
        results[f"{start}-{end}"] = result
    return results


if __name__ == "__main__":
    print(json.dumps({path: analyze(path) for path in sys.argv[1:]}, indent=2))
