#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void read_through_sample(int size);
void dump_remainder();
int main(int argc, char **argv)
{
  if(argc == 3)
  {
    /* first seek to beginning of PCM section */
    unsigned int c;
    int i=0;
    /* -1 so we don't lose the first character! */
    while((c=getchar()) != EOF && i < (atoi(argv[1]) - 1)) {
/*      putchar(c);*/
      i++;
    }

    read_through_sample(atoi(argv[2]));
    dump_remainder();
    return 0;
  }
  else
  {
    fprintf(stderr, "Error: need two arguments for the starting offset of the sample\nand the size of the sample.\n");
  }
}

void read_through_sample(int size)
{
  /*int little=is_little_endian();*/
  int i=0;
  unsigned int c;
  while((c=getchar()) != EOF && i < size) {
    i++;
  }
}

void dump_remainder() {
  unsigned int c;
  while((c=getchar()) != EOF) {
    putchar(c);
  }
}
