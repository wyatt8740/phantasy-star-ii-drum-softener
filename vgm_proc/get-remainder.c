#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/* after pcm is dumped, run this to seek to end of PCM and dump out the rest of
   the file from there. */
int pcm_seek_to_end();
void dump();
int main(int argc, char **argv)
{
  /* first seek to beginning of PCM section */
  unsigned int c;
  while(!feof(stdin))
  {
    c=getchar();
    if(c == 0147) /* 0x67, in octal */
    {
      c=getchar();
      if(c == 0146) /* 0x66, in octal */
      {
        pcm_seek_to_end();
        dump();
      }
    }
  }
  return 0;
}

int pcm_seek_to_end()
{
  unsigned int c;
  uint32_t siz=0;
  if((!feof(stdin))) {
    /* byte 1 is sample type, copy and do nothing else */
    c=getchar();
  }
  /* get our size. */
  /* bizarrely seems to work on both endians (as long as there's an 8 bit byte
     size) */
  int i=0;
  while(i<4)
  {
    if((!feof(stdin))) {
      c=getchar();
      siz=siz | c << (i * 8);
    }
    i++;
  }
/*  fprintf(stderr, "size is 0x%08x (base 10: %lu)\n", (unsigned long)siz, (unsigned long)siz);*/
  uint32_t iterations=0;
  while( (!feof(stdin)) && iterations < siz) {
    getchar();
    iterations++;
  }
  return 0;
}

void dump()
{
  unsigned int c=0;
  while((c=getchar()) != EOF) {
    putchar(c);
  }
}