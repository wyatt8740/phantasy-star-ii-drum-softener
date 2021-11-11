Makes the Japanese release of Phantasy Star II's drums quieter, to save Nei's
delicate Numan ears.

Also provides for making an english game that uses the Japanese version's
sound engine, or vice versa (The game has totally different engines in the
different releases, and this results in some subtle sound differences.
Additionally, the drum samples differ).

This is code I wrote as fast as possible to "just get the job done," so it's a
bit brittle and weird. It has minimal training wheels or guard rails. You will
want to be careful using these.

Basically, I wrote shell scripts where possible, and to avoid doing proper file
I/O in C I just did everything as standard input filters that write to
standard output.

I could probably have done everything in one go in one file, but I wrote this
to automate the process I did manually on the first file I tried this with.
I already had the code for changing the sample volume written, and so I sort
of bolted stuff around that.

This repository contains C, shell scripts, and assembly to make:

* Phantasy Star II (Japan) .VGM rips with quieter snare drums

* Phantasy Star II game modifications, to make the game itself use quieter drums

* Phantasy Star II game modifications to make the US release use the Japanese 
  sound engine, and vice versa
  
It also contains my recently completed save file for Phantasy Star II, which
has all sound test entries unlocked. The first save slot starts you in the
town where the sound test guy (the musician, Ustvestia) is located. By
the way, this save data appears to work under the Japanese version of the
game as well, albeit with garbage character names.
  
This repository does not include all the code and assets necessary to make a
binary copy of the game; If you want that, you should look for the disassembly
project for this game. That said, it does contain some files that I
replaced/superimposed on top of the disassembly project to make my stuff work.
I don't think I wrote a single line of actual assembly for this unless you
count `db` (define byte), although I did  do some work in ASL assembler macros
to make configuration options for the things I wanted to do.

For making a game, you want the files under `ps2disasm`. For the tools I used
to manipulate the PCM tracks, you should look under the `ps2disasm/tools`
directory.

For VGM stuff, you should look under `vgm_proc`. Note that the VGM stuff
is less advanced than the stuff for the disassembly, and doesn't necessarily
work quite as well. For instance, the game disassembly based tools can be used
to individually reduce the volume of specific samples; the VGM ones are older
and apply a flat reduction to all samples at once unless you do extra work.

I might fix this later, but the VGM's are slightly more annoying to work with
for this. We'll see if I get motivated enough to do it. Pull requests welcome.
