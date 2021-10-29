#! /bin/sh
# pass an input file as an argument.
# side effect: will scrozzle temp.vgm if such a file exists in the current
# directory.
# will also scrozzle 01_temp.bin, 02_temp_pcm.bin, 03_temp.bin,
# 02_temp_quiet_pcm.bin.

# optional second argument: volume divisor

#set -x

mergevgm() {
  rm -f temp.vgm
  while [ "$#" -gt 1 ]; do
    cat "$1" >> temp.vgm
    shift 1
  done
  mv temp.vgm "$1"
}

./get-header < "$1" > 01_temp.bin
./get-pcm < "$1" > 02_temp_pcm.bin
./get-remainder < "$1" > 03_temp.bin
./shiftdown "$2" < 02_temp_pcm.bin > 02_temp_quiet_pcm.bin

mergevgm 01_temp.bin 02_temp_quiet_pcm.bin 03_temp.bin "$(basename "$1")"

rm 01_temp.bin
rm 02_temp_pcm.bin
rm 03_temp.bin
rm 02_temp_quiet_pcm.bin
