#! /bin/sh
# args: rom name, start offset of sample, and length of sample

# currently this just fixes one sample at a time, so for example the snare
# drums. i found the offsets in the rom by replacing part of the PCM in the
# disassembly with my name as an ASCII string at the beginning and end and
# then looking in a hex editor. Yes, this is quite a roundabout way of doing
# things. I did not want to parse the assembly file.

# if you want the offsets in my hybrid US-JP rom
# (JP sound engine with otherwise US contents), my offset for the snare drum
# was 780135 bytes in (decimal) and the length of the snare drum sample was
# 2048 bytes.


ROM="$1"
STARTOFFSET="$2"
SAMPLESIZE="$3"
VOL_MOD="$4"

# where to put the pieces
WORKINGDIR="./temp"
# what to call the pieces
PREAMBLE="preamble_rom.bin"
SAMPLERAW="sample_raw.bin"
SAMPLEMOD="sample_mod.bin"
REMAINDER="remainder_rom.bin"

OUTPUTROM="VOLUME_HACKED.bin"

set -x
# extract lead-up to the sample
./utils/preamble "$STARTOFFSET" < "$ROM" > "$WORKINGDIR"'/'"$PREAMBLE"

# dump the actual sample
./utils/samplerip "$STARTOFFSET" "$SAMPLESIZE" < "$1" > "$WORKINGDIR"'/'"$SAMPLERAW"

# need to internally seek to startoffset, read forward samplesize bytes, and then start dumping.
./utils/remainder "$STARTOFFSET" "$SAMPLESIZE" < "$1" > "$WORKINGDIR"'/'"$REMAINDER"

# apply volume correction
if [ "$VOL_MOD" ]; then
  ./utils/correct_vol "$VOL_MOD" < "$WORKINGDIR"'/'"$SAMPLERAW" > "$WORKINGDIR"'/'"$SAMPLEMOD"
fi

cat "$WORKINGDIR"'/'"$PREAMBLE" "$WORKINGDIR"'/'"$SAMPLEMOD" "$WORKINGDIR"'/'"$REMAINDER" > "$OUTPUTROM"
./utils/fixheader "$OUTPUTROM"
