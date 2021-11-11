CC=cc
CFLAGS=-Wall
LDFLAGS=

.PHONY: all

all: get-header get-pcm get-remainder shiftdown


%: %.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f get-header get-pcm get-remainder shiftdown

