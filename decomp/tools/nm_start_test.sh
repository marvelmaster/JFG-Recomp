#!/bin/bash
# bash tools/nm_start_test.sh <level> <char> [secs]  -> direct-start build, report mode/level/loaded overlays
cd ~/jfg_nm
NM_START_LEVEL=$1 NM_START_CHAR=$2 bash tools/nm_build.sh ~/bis/start_$1_$2.z64 > /dev/null
E=~/bis/start_$1_$2.elf
s() { mips-linux-gnu-nm $E | grep " $1$" | cut -c1-8; }
M64_OVL_PTR=0x$(s overlayTable) M64_STEP=${3:-12} bash tools/probe_rom.sh ~/bis/start_$1_$2.z64 ${3:-12} mode=0x$(s mainGameMode) level=0x$(s D_800A3250_A3E50) | grep -E "^t=|loaded|COP0"
