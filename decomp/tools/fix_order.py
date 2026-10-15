#!/usr/bin/env python3
"""Restore the original GLOBAL_ASM function order in a source file.

Each function is a "block": either a bare `#pragma GLOBAL_ASM` line or the
whole `#ifdef NON_MATCHING ... #else <pragma> #endif` around it. The block
slots stay where they are; only which function sits in which slot changes, so
that the asm fallbacks appear in the same order as in the original project.

Usage: tools/fix_order.py <original project root> <src/file.c> [...]
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from check_integrity import active_pragmas  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
PRAGMA = re.compile(r'#pragma\s+GLOBAL_ASM\("([^"]+)"\)')


def blocks(lines):
    found = []
    for i, line in enumerate(lines):
        m = PRAGMA.search(line)
        if not m:
            continue
        start = end = i
        depth = 0
        for j in range(i - 1, -1, -1):
            s = lines[j].strip()
            if s.startswith("#endif"):
                depth += 1
            elif s.startswith("#if"):
                if depth == 0:
                    if re.match(r"#ifdef\s+NON_MATCHING\b", s):
                        start = j
                    break
                depth -= 1
        if start != i:
            depth = 0
            for j in range(i + 1, len(lines)):
                s = lines[j].strip()
                if s.startswith("#if"):
                    depth += 1
                elif s.startswith("#endif"):
                    if depth == 0:
                        end = j
                        break
                    depth -= 1
        found.append((start, end, m[1]))
    return found


def fix(orig_root, rel):
    path = ROOT / rel
    raw = path.read_text(encoding="utf-8", newline="")
    nl = "\r\n" if "\r\n" in raw else "\n"
    lines = raw.split(nl)
    want = active_pragmas(orig_root, rel)
    bl = blocks(lines)
    by_name = {b[2]: b for b in bl}
    slots = [b for b in bl if b[2] in want]
    if [b[2] for b in slots] == want:
        print(f"{rel}: already in order")
        return
    if sorted(b[2] for b in slots) != sorted(want):
        print(f"{rel}: block set differs from original, not touching")
        return
    out, pos = [], 0
    for slot, name in zip(slots, want):
        out += lines[pos:slot[0]]
        s, e, _ = by_name[name]
        out += lines[s:e + 1]
        pos = slot[1] + 1
    out += lines[pos:]
    path.write_text(nl.join(out), encoding="utf-8", newline="")
    print(f"{rel}: reordered {len(slots)} blocks")


def main():
    orig = Path(sys.argv[1])
    for rel in sys.argv[2:]:
        fix(orig, rel.replace("\\", "/"))


if __name__ == "__main__":
    main()
