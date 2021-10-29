#include <stdio.h>
/* extract header */
int main(int argc, char *argv)
{
  unsigned char c;
  int i=0;
  while(i<7) {
    if(!feof(stdin))
    {
      c=getchar();
      putchar(c);
    }
    i++;
  }
  while (!feof(stdin))
  {
    c = getchar();
    putchar((char)((int)c/(int)4));
  }
  return 0;
}
