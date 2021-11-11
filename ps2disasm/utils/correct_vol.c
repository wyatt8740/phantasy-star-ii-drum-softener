#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MULT 1

int main(int argc, char **argv)
{
#ifdef MULT
  double multiplier=0.33; /* default to 0.33, which I think sounds pleasant */
#else
  int divisor=2;
#endif
  if(argc > 1)
  {
    double d=atof(argv[1]);
    if(d > 0.0) /* basically not zero */
    {
      multiplier=d;
    }
  }
  else
  {
    fprintf(stderr,"Error: need an argument for volume multiplier.\n");
    return 1;
  }
  unsigned int c=0;
/*  int i=0;
  while(i<7) {
    if(c != EOF && !feof(stdin))
    {
      c=getchar();
      putchar(c);
    }
    i++;
    }*/

  /* since unsigned we need to have a correction factor since we'll deviate from silence = 0x80 and get popping */
  unsigned int offset=(unsigned int)(0200 - ((double)0200 * (double)multiplier)); /* 0200 = 0x80 in octal */
  fprintf(stderr,"initial correction value for pcm is %u\n", offset);
  offset += (0200 - ((unsigned int)((double)0200 * (double)multiplier) + offset)); /* correcting for rounding errors */
  fprintf(stderr,"final correction value for pcm is %u\n", offset);  
  while (!feof(stdin))
  {
    c = getchar();
    if(c != EOF)
    {
#ifdef MULT
      putchar((char)((int)((double)c * (double)multiplier))+offset);
#else
      putchar((int)((int)c/divisor));
#endif
    }
  }
  return 0;
}
