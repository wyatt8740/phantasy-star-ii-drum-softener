CC=cc
CFLAGS=-Wall
LDFLAGS=

.PHONY: all

all: preamble samplerip remainder correct_vol



%: %.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f preamble samplerip remainder correct_vol
