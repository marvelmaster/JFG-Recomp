#!/usr/bin/env bash
# Run in WSL/Linux. RSP_RECOMP may select another overlay-capable RSPRecomp.
set -euo pipefail
project_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
rsp_generator="${RSP_RECOMP:-$HOME/N64Recomp/build/RSPRecomp}"
if [[ ! -x "$rsp_generator" ]]; then
    printf 'RSPRecomp executable not found: %s\nSet RSP_RECOMP to an overlay-capable generator.\n' "$rsp_generator" >&2
    exit 1
fi
cd -- "$project_dir"
"$rsp_generator" n_aspMain.us.rev0.toml
python3 tools/instrument_audio_rsp.py
