#!/usr/bin/env python3
"""Wrap unguarded `/* decomp: externs */` blocks in #ifdef NON_MATCHING.

Only declaration-only blocks are touched: every line up to the next
preprocessor conditional / GLOBAL_ASM pragma must be an extern, a prototype,
a typedef/struct body, a #define, a comment or blank. Anything else (a real
definition) makes the file be reported and skipped, because guarding it would
remove it from the asm build.

Usage: tools/guard_externs.py [--dry] <src/file.c> [...]
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MARK = "/* decomp: externs */"
STOP = re.compile(r"\s*#\s*(if|ifdef|ifndef|pragma\s+GLOBAL_ASM|else|endif)\b")
PROTO = re.compile(r"^[\w\s\*\(\),\[\]\.]+\([^;{]*\)\s*;\s*(//.*|/\*.*\*/\s*)?$")


def decl_only(lines):
    depth = 0  # brace depth inside typedef/struct bodies
    pending = ""  # multi-line prototype being collected
    for raw in lines:
        s = raw.strip()
        if pending:
            pending += " " + s
            if s.endswith(";"):
                if not PROTO.match(pending):
                    return False, raw
                pending = ""
            continue
        if depth:
            depth += s.count("{") - s.count("}")
            continue
        if not s or s.startswith("//") or s.startswith("/*") or s.startswith("*"):
            continue
        if s.startswith("#define") or s.startswith("#include") or s.startswith("#undef"):
            continue
        if s.startswith("extern ") and "=" not in s and "{" not in s:
            continue
        if s.startswith("typedef") or s.startswith("struct ") or s.startswith("union ") \
                or s.startswith("enum "):
            depth = s.count("{") - s.count("}")
            if "=" in s:
                return False, raw
            continue
        if PROTO.match(s):
            continue
        if "(" in s and not s.endswith(";") and "{" not in s and "=" not in s:
            pending = s
            continue
        return False, raw
    return (depth == 0 and not pending), None


def guard(rel, dry):
    p = ROOT / rel
    raw = p.read_text(encoding="utf-8", newline="")
    nl = "\r\n" if "\r\n" in raw else "\n"
    L = raw.split(nl)
    idx = [i for i, l in enumerate(L) if l.strip() == MARK]
    if not idx:
        return f"{rel}: no marker"
    i = idx[0]
    near = [l.strip() for l in L[max(0, i - 1):i + 2]]
    if any(re.match(r"#ifdef\s+NON_MATCHING", n) for n in near):
        return f"{rel}: already guarded"
    j = i + 1
    while j < len(L) and not STOP.match(L[j]):
        j += 1
    ok, bad = decl_only(L[i + 1:j])
    if not ok:
        return f"{rel}: SKIP (non-declaration line: {bad.strip()[:70]!r})"
    end = j
    while end > i + 1 and not L[end - 1].strip():
        end -= 1
    if dry:
        return f"{rel}: would guard lines {i + 2}-{end}"
    L.insert(end, "#endif")
    L.insert(i + 1, "#ifdef NON_MATCHING")
    p.write_text(nl.join(L), encoding="utf-8", newline="")
    return f"{rel}: guarded lines {i + 2}-{end}"


def main():
    args = sys.argv[1:]
    dry = "--dry" in args
    for rel in (a for a in args if a != "--dry"):
        print(guard(rel.replace("\\", "/"), dry))


if __name__ == "__main__":
    main()
