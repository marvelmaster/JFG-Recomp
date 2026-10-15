#!/bin/bash
# Build a NON_MATCHING ROM with the main code from C (overlays from asm).
# Run in WSL:  bash tools/nm_build.sh <out.z64> [files to keep on asm ...]
# Example (bisecting): bash tools/nm_build.sh /tmp/a.z64 src/objects.c src/track.c
set -e
OUT="$1"; shift
ASM_FILES="$*"
cd ~/jfg_nm
SCOPE=${NM_SCOPE-main}  # NM_SCOPE= (empty) -> overlays from C too
MK="make -s -j16 DECOMP_MEASURE=1 CC_CHECK=true NM_SCOPE=$SCOPE"
# compile flags are not tracked by make: rebuild every main C object each time
rm -f build/src/*.c.o build/src/libultra/*.c.o build/jfg.us.elf build/jfg.us.z64
[ -z "$SCOPE" ] && find build/src/overlays -name "*.c.o" -delete 2>/dev/null || true
mkdir -p build/nm_syms
for f in undefined_syms.txt undefined_funcs_auto.us.txt undefined_syms_auto.us.txt libultra_undefined_syms.us.txt; do
  [ -f build/nm_syms/$f ] || cp ver/symbols/$f build/nm_syms/$f
done
$MK NM_ASM_FILES="$ASM_FILES" > ~/nm_build.log 2>&1 || true
# shift-safe symbol files from the freshly built objects, then link again
python3 tools/nm_filter_syms.py ~/jfg/build/jfg.us.elf build build/nm_syms ver/symbols/undefined_syms.txt \
  ver/symbols/undefined_funcs_auto.us.txt ver/symbols/undefined_syms_auto.us.txt ver/symbols/libultra_undefined_syms.us.txt > ~/nm_syms.log
rm -f build/jfg.us.elf build/jfg.us.z64
$MK NM_ASM_FILES="$ASM_FILES" >> ~/nm_build.log 2>&1 || true
if ! [ -f build/jfg.us.z64 ]; then echo "BUILD FAILED, see ~/nm_build.log"; exit 1; fi
cp build/jfg.us.z64 "$OUT"
cp build/jfg.us.elf "${OUT%.z64}.elf"
~/jfg/.venv/bin/python3 tools/nm_postlink.py ~/jfg/build/jfg.us.elf build/jfg.us.elf "$OUT" tools/nm_manual_ort.txt | tail -1
~/jfg/tools/n64crc "$OUT" > /dev/null
echo "ROM: $OUT"
