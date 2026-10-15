#!/bin/bash
# bash tools/nm_test.sh <name> [asm files...] -> builds ~/bis/<name>.z64, runs it with video (WSLg).
# GOOD when the screenshot at frame 3600 is reached (attract-mode 3D scene; original needs ~150 s).
# NM_AUTO_INPUT=1 NM_TEST_FRAMES=1200,5400 NM_TEST_SECS=500: scripted pad (title -> new game -> name entry -> intro).
# NM_TEST_MINSIZE=40000 (with NM_AUTO_INPUT=1 NM_TEST_FRAMES=1200 NM_TEST_SECS=120): GOOD when the first screenshot
#   is at least that big - the name-entry screen with its 3D objects is ~94 KB, without them ~2 KB. Fast and not
#   timing dependent (long runs turned out flaky when the PC is busy).
NAME=$1; shift
bash ~/jfg_nm/tools/nm_build.sh ~/bis/$NAME.z64 "$@" > /dev/null
end=$(mips-linux-gnu-nm ~/bis/$NAME.elf | grep " main_ROM_END$" | cut -c1-8)
FR=${NM_TEST_FRAMES:-1200,3600}
need=$(echo "$FR" | tr ',' '\n' | wc -l)
for try in 1 2; do
  rm -rf /tmp/t_$NAME
  n=$(bash ~/jfg_nm/tools/rom_shots.sh ~/bis/$NAME.z64 $FR /tmp/t_$NAME ${NM_TEST_SECS:-200} | grep -c Captured)
  [ "$n" -ge 1 ] && break   # no screenshot at all: emulator hiccup, try once more
done
sz=$(stat -c %s $(ls /tmp/t_$NAME/*.png 2>/dev/null | head -1) 2>/dev/null || echo 0)
if [ -n "$NM_TEST_MINSIZE" ]; then
  [ "$sz" -ge "$NM_TEST_MINSIZE" ] && r=GOOD || r=BAD
else
  [ "$n" -ge "$need" ] && r=GOOD || r=BAD
fi
echo "$NAME main_ROM_END=$end shots=$n size=$sz result=$r"
