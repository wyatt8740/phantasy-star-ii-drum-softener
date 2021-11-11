#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int dump();
int is_little_endian();
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
        putchar(0147);
        putchar(c);
        dump();
      }
    }
  }
  return 0;
}

int dump()
{
  /*int little=is_little_endian();*/
  unsigned int c;
  uint32_t siz=0;
  /* ALERT: this function has the potential to be endian specific code.
     But I tested it on a powerbook and I think it seems to be okay. */
  if((!feof(stdin))) {
    /* byte 1 is sample type, copy and do nothing else */
    putchar((c=getchar()));
  }

  /* get our size. */
  int i=0;
  /* little endian */
/*  if(little) {
    fprintf(stderr, "Little-endian mode\n");*/

  /* big endian */
  /* this seems to work in both endians. Huh. */
  while(i<4)
  {
    if((!feof(stdin))) {
      c=getchar();
      putchar(c);
      siz=siz | c << (i * 8);
    }
    i++;
  }

/*  }
    else { 
    while(i<4)
    {
      if((!feof(stdin))) {
        c=getchar();
        siz=siz | c << ((3-i) * 8);
      }
      i++;
    }
  }*/
/*  fprintf(stderr, "size is 0x%08x (base 10: %lu)\n", (unsigned long)siz, (unsigned long)siz);*/
  uint32_t iterations=0;
  while((!feof(stdin)) && iterations < siz) {
    putchar(getchar());
    iterations++;
  }
  return 0;
}

/*int is_little_endian()
{
  int e=1;
  return (int)*((unsigned char *)&e) == 1;
}*/
