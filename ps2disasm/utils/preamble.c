#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void dump();
int main(int argc, char **argv)
{
  if(argc == 2)
  {
    /* first seek to beginning of PCM section */
    unsigned int c;
    int i=0;
    while((c=getchar()) != EOF && i < atoi(argv[1])) {
      putchar(c);
      i++;
    }
    /* dump(); */
    return 0;
  }
  else
  {
    fprintf(stderr, "Error: need a single argument for the starting offset of the sample.\n");
  }
}

void dump()
{
  /*int little=is_little_endian();*/
  unsigned int c;
  while((c=getchar()) != EOF) {
    putchar(c);
  }
}
