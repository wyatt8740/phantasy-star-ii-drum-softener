#! /bin/sh
# pass all files to merge as arguments in order

rm -f temp.vgm
while [ "$#" -gt 0 ]; do
  cat "$1" >> temp.vgm
  shift 1
done