#!/usr/bin/env python3
"""Work queue for the matching round.

  mqueue.py init <match.json>   build the queue from a match_report.py json (non-matching decomp funcs)
  mqueue.py claim [n] [maxlines] claim up to n functions from one file not claimed by anyone (smallest first)
  mqueue.py done <id> <func>=match|nomatch [...]
  mqueue.py status
State: build/mqueue_state.json
"""
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
STATE = ROOT / "build" / "mqueue_state.json"


def asm_lines(func):
    hits = list((ROOT / "asm" / "nonmatchings").rglob(f"{func}.s"))
    return sum(1 for _ in hits[0].open(encoding="utf-8")) if hits else 99999


def decomp_funcs():
    out = {}
    for p in (ROOT / "src").rglob("*.c"):
        lines = p.read_text(encoding="utf-8").splitlines()
        for i, l in enumerate(lines):
            m = re.search(r'#pragma GLOBAL_ASM\("[^"]*/(\w+)\.s"\)', l)
            if m and i and lines[i - 1].strip().startswith("#else"):
                out[m[1]] = str(p.relative_to(ROOT)).replace("\\", "/")
    return out


def load():
    return json.loads(STATE.read_text())


def save(s):
    STATE.write_text(json.dumps(s, indent=1))


def main():
    cmd = sys.argv[1]
    if cmd == "init":
        res = {n: v for f in json.load(open(sys.argv[2])).values() for n, v in f.items()}
        dec = decomp_funcs()
        todo = [(asm_lines(n), n, f) for n, f in dec.items() if n in res and not res[n]]
        todo.sort()
        save({"todo": [[n, f, sz] for sz, n, f in todo], "active": {}, "next": 1,
              "matched": [n for n in dec if res.get(n)], "nomatch": []})
        print(f"{len(todo)} functions queued")
    elif cmd == "claim":
        n = int(sys.argv[2]) if len(sys.argv) > 2 else 5
        maxl = int(sys.argv[3]) if len(sys.argv) > 3 else 10 ** 9
        s = load()
        busy = {f for a in s["active"].values() for f in [a["file"]]}
        pick, fname = [], None
        for item in s["todo"]:
            if item[1] in busy or item[2] > maxl:
                continue
            if fname is None:
                fname = item[1]
            if item[1] == fname and len(pick) < n:
                pick.append(item)
        if not pick:
            print("{}")
            return
        for item in pick:
            s["todo"].remove(item)
        bid = s["next"]
        s["next"] += 1
        s["active"][str(bid)] = {"file": fname, "funcs": [[p[0], p[2]] for p in pick]}
        save(s)
        print(json.dumps({"id": bid, "file": fname, "funcs": [[p[0], p[2]] for p in pick]}))
    elif cmd == "done":
        s = load()
        a = s["active"].pop(sys.argv[2])
        for arg in sys.argv[3:]:
            fn, res = arg.split("=")
            (s["matched"] if res == "match" else s["nomatch"]).append(fn)
        save(s)
        print(f"matched {len(s['matched'])}, nomatch {len(s['nomatch'])}, todo {len(s['todo'])}, active {len(s['active'])}")
    elif cmd == "status":
        s = load()
        print(f"matched {len(s['matched'])}, nomatch {len(s['nomatch'])}, todo {len(s['todo'])}, active {list(s['active'])}")


if __name__ == "__main__":
    main()
