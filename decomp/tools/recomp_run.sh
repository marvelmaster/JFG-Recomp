#!/bin/bash
# Static recompilation of JFG with N64Recomp (run in WSL). Needs ~/N64Recomp/build/N64Recomp and an
# ELF with section-relative symbols: ~/bis/rcbase.elf  (NM_SCOPE=none bash tools/nm_build.sh ~/bis/rcbase.z64).
# Output: ~/jfg_rc/RecompiledFuncs (C code of every function, main + all overlays).
set -e
W=/mnt/f/SelfmadeTools/JFG_Decomp
mkdir -p ~/jfg_rc/RecompiledFuncs; cd ~/jfg_rc
# base config + generated ra hooks for every `jal TrapDanglingJump` (see tools/recomp_gen.py)
python3 $W/tools/recomp_gen.py ${RC_ELF:-~/bis/rcbase.elf} $W/baseroms/baserom.us.z64 .
cat $W/recomp/jfg.us.toml jfg.us.hooks.toml > jfg.us.toml
rm -f RecompiledFuncs/*
~/N64Recomp/build/N64Recomp jfg.us.toml > ~/rc_run.log 2>&1 || { grep -B3 "^Error recompiling" ~/rc_run.log | head -20; echo FAILED; exit 1; }
python3 $W/tools/recomp_anim.py jfg.us.syms.toml jfg.us.recomp.z64 RecompiledFuncs
python3 $W/tools/recomp_fpu.py RecompiledFuncs
echo "OK: $(ls RecompiledFuncs | wc -l) files, $(du -sh RecompiledFuncs | cut -f1)"
