#!/bin/bash
# Register rebuilt JFG ROMs in Project64's databases (Git Bash on Windows).
# Project64 picks per-game settings by the header CRC; a rebuilt ROM has a new CRC and would run
# with defaults (fatal error after the Rare logo). This copies the original (U) entry
# [8A6009B6-94ACE150-C:45] of Project64.rdb and Video.rdb under the CRC of each given ROM.
# Usage: bash tools/pj64_register.sh <rom.z64> [...]      (close Project64 first)
#        PJ64_DIR="/c/Program Files (x86)/Project64 3.0" overrides the install dir.
PJ=${PJ64_DIR:-"/c/Program Files (x86)/Project64 3.0"}
ORIG="8A6009B6-94ACE150-C:45"
if tasklist 2>/dev/null | grep -qi "^Project64.exe"; then echo "Project64 is running - close it first (its databases are locked)"; exit 1; fi
for rom in "$@"; do
  h=$(xxd -s 16 -l 8 -p "$rom" | tr a-f A-F)
  key="${h:0:8}-${h:8:8}-C:45"
  name="JFG decomp ($(basename "$rom"))"
  for db in Project64.rdb Video.rdb; do
    f="$PJ/Config/$db"
    [ -f "$f" ] || { echo "missing $f"; continue; }
    if grep -qF "[$key]" "$f"; then echo "$db: $key already present"; continue; fi
    [ -f "$f.bak_jfg" ] || cp "$f" "$f.bak_jfg"
    # body of the original block (lines after the header up to the next blank line)
    body=$(tr -d '\r' < "$f" | awk -v k="[$ORIG]" '$0==k{on=1;next} on&&/^\[/{exit} on&&NF{print}' | grep -v "^Good Name=")
    printf '\r\n[%s]\r\nGood Name=%s\r\n' "$key" "$name" >> "$f"
    printf '%s\n' "$body" | sed 's/$/\r/' >> "$f"
    echo "$db: added $key ($name)"
  done
done
