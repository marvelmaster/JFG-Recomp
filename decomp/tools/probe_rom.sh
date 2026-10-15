#!/bin/bash
# bash tools/probe_rom.sh <rom> [secs] [name=addr ...]  -> PC trace + RAM words (headless mupen64plus)
export LD_LIBRARY_PATH=~/m64/root/usr/lib/x86_64-linux-gnu
python3 -u "$(dirname "$0")/m64probe.py" "$@" 2>&1 | grep -vE "^(startup|rom open ok|plugins ok|running)$|WARN:|MSG: (No |Failed to open video|OpenGL)"
