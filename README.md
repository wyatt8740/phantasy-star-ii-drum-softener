Makes the Japanese release of Phantasy Star II's drums quieter, to save Nei's
delicate Numan ears.

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

You want to run `process.sh`, though.

Do something like:

    ./process.sh jp/05\ -\ Pleasure.vgm 0.33
    
…to output a file in your current directory called `05 - Pleasure.vgm`, with
the amplitude of the drum samples multiplied by 1/3rd.
    
**NOTE: DO NOT PUT YOUR INPUT VGM FILES IN THE SAME DIRECTORY AS YOUR CURRENT
ONE. IF YOU DO, THEY WILL BE ERASED OR OTHERWISE SCROZZLED.**

License: LGPL. If you really want to use this for something and don't like
LGPL, ask me and I might be willing to change it. I'm not too attached
to LGPL.
