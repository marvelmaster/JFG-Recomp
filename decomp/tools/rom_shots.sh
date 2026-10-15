#!/bin/bash
# bash tools/rom_shots.sh <rom> <frames e.g. 300,900> <outdir> [seconds]
# Runs the ROM in mupen64plus (rice video via WSLg/llvmpipe) and saves screenshots at the given frames.
ROM=$1; FR=$2; OUT=$3; T=${4:-60}
R=~/m64/root
export LD_LIBRARY_PATH=$R/usr/lib/x86_64-linux-gnu
rm -rf ~/.local/share/mupen64plus/save/*  # fresh EEPROM/flash: a save from an earlier run changes the menu flow
rm -rf /tmp/shots_$$; mkdir -p /tmp/shots_$$ "$OUT"
timeout $T $R/usr/games/mupen64plus --noosd --windowed --resolution 320x240 --corelib $R/usr/lib/x86_64-linux-gnu/libmupen64plus.so.2 \
  --plugindir $R/usr/lib/x86_64-linux-gnu/mupen64plus --datadir $R/usr/share/games/mupen64plus \
  --gfx mupen64plus-video-rice.so --audio dummy --input dummy --rsp mupen64plus-rsp-hle.so \
  --testshots $FR --sshotdir /tmp/shots_$$ "$ROM" > /tmp/shots_$$.log 2>&1
grep -E "Captured|Error|rror" /tmp/shots_$$.log | head
cp /tmp/shots_$$/*.png "$OUT"/ 2>/dev/null; ls "$OUT"
