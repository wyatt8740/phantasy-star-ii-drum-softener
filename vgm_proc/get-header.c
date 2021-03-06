#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* note: I should really read 0x34 instead of assuming header length. */
/*
 * [VGM 1.50 additions:]
 * 0x34: VGM data offset (32 bits)
 *         Relative offset to VGM data stream.
 *         If the VGM data starts at absolute offset 0x40, this will contain 
 *         value 0x0000000C. For versions prior to 1.50, it should be 0 and the
 *         VGM data must start at offset 0x40.
 *
 */

int get_header_remaining_length() /* to call at offset 0x34 */
{
  int i=0;
  unsigned int c=0;
  uint32_t siz=0;
  while(i<4)
  {
    if((!feof(stdin))) {
      c=getchar();
      putchar(c);
      siz=siz | c << (i * 8);
    }
    i++;
  }
  if(siz == 0)
  {
    /* we must be using an older VGM file that's a static 0x40 bytes long. */
    siz=12; /* 0x0c bytes left in the header */
  }
  return siz;
}

/* currently i do not use the above function; i just look for a ym2612 PCM
   bank. For my purposes, that's enough. */

int main(int argc, char **argv)
{
  unsigned char c;
  int found=0;
  while(!feof(stdin) && found == 0)
  {
    c=getchar();
    if(c == 0147) /* 0x67, in octal */
    {
      c=getchar();
      if(c == 0146) /* 0x66, in octal */
      {
        goto done; /* yeah, yeah. I know. */
      }
      else
      {
        putchar(0147);
      }
    }
    putchar(c);
  }
done:
  return 0;
}
