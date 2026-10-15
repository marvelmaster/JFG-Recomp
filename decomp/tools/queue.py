#!/usr/bin/env python3
"""Work queue for parallel decompilation agents (file-disjoint batches).

  queue.py claim [batch_size]  -> claims next batch whose files are not in use,
                                  prints it as JSON (id, file, functions)
  queue.py done <id>           -> releases a batch
  queue.py status              -> shows active batches

Remaining functions are re-read from the sources every time, so finished or
skipped work never needs bookkeeping beyond the active list.
"""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from decomp_progress import scan  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
STATE = ROOT / "build" / "queue_state.json"
MAIN_ONLY = "--main-only" in sys.argv
if MAIN_ONLY:
    sys.argv.remove("--main-only")


def load():
    if STATE.exists():
        return json.loads(STATE.read_text())
    return {"next_id": 1, "active": {}, "skipped": {}}


def save(state):
    STATE.parent.mkdir(parents=True, exist_ok=True)
    STATE.write_text(json.dumps(state, indent=1))


def claim(size):
    state = load()
    busy = {f for b in state["active"].values() for f in b["files"]}
    data = scan()
    # game code first, libultra last; larger files first so they start early
    files = sorted(data, key=lambda f: ("libultra" in f, -len(data[f]["asm"])))
    items, count = {}, 0
    for f in files:
        todo = [fn for fn in data[f]["asm"] if fn not in state["skipped"].get(f, [])]
        if not todo or f in busy or (MAIN_ONLY and "overlays/" in f):
            continue
        take = todo[:size - count]
        items[f] = take
        count += len(take)
        if count >= size:
            break
    if not items:
        print("{}")
        return
    batch = {"id": state["next_id"], "files": items}
    state["next_id"] += 1
    state["active"][str(batch["id"])] = batch
    save(state)
    print(json.dumps(batch))


def asm_lines(fn):
    hits = list((ROOT / "asm" / "nonmatchings").rglob(f"{fn}.s"))
    return sum(1 for _ in hits[0].open(encoding="utf-8")) if hits else 0


def done(bid, skipped):
    # only genuinely huge functions are parked for the dedicated big-function round;
    # smaller skips go back into the queue
    state = load()
    tries = state.setdefault("tries", {})
    for fn in skipped:
        tries[fn] = tries.get(fn, 0) + 1
    # park huge functions immediately, others after two failed batches
    skipped = [fn for fn in skipped if asm_lines(fn) >= 400 or tries[fn] >= 2]
    batch = state["active"].pop(str(bid), None)
    if batch:
        for fn in skipped:
            for f, fns in batch["files"].items():
                if fn in fns:
                    state["skipped"].setdefault(f, []).append(fn)
    save(state)


def claim_big():
    """Big-function round: one parked function per batch, smallest first."""
    state = load()
    busy = {f for b in state["active"].values() for f in b["files"]}
    data = scan()
    failed = set(state.get("failed", []))
    cands = []
    for f, fns in state["skipped"].items():
        if f in busy or f not in data:
            continue
        for fn in fns:
            if fn in data[f]["asm"] and fn not in failed:
                cands.append((asm_lines(fn), f, fn))
    if not cands:
        print("{}")
        return
    size, f, fn = min(cands)
    fns = [fn]
    if size < 400:  # small re-tries: bundle up to 5 from the same file
        fns = [c[2] for c in sorted(cands) if c[1] == f and c[0] < 400][:5]
    for x in fns:
        state["skipped"][f].remove(x)
    batch = {"id": state["next_id"], "files": {f: fns}, "big": True}
    state["next_id"] += 1
    state["active"][str(batch["id"])] = batch
    save(state)
    print(json.dumps(batch))


def done_big(bid, ok):
    state = load()
    batch = state["active"].pop(str(bid), None)
    if batch and not ok:
        for fns in batch["files"].values():
            state.setdefault("failed", []).extend(fns)
    save(state)


def main():
    cmd = sys.argv[1] if len(sys.argv) > 1 else "status"
    if cmd == "claim":
        claim(int(sys.argv[2]) if len(sys.argv) > 2 else 20)
    elif cmd == "claimbig":
        claim_big()
    elif cmd == "donebig":
        done_big(sys.argv[2], sys.argv[3] == "ok")
    elif cmd == "done":
        done(sys.argv[2], sys.argv[3:])
        print("parked:", load()["skipped"] and sum(len(v) for v in load()["skipped"].values()))
    else:
        print(json.dumps(load()["active"], indent=1))


if __name__ == "__main__":
    main()
