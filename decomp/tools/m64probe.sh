#!/bin/bash
# wrapper: bash tools/m64probe.sh <rom> [secs] [name=addr ...]
export LD_LIBRARY_PATH=~/m64/root/usr/lib/x86_64-linux-gnu
exec python3 "$(dirname "$0")/m64probe.py" "$@"
