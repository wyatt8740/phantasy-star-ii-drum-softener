#include <stdio.h>

int main(int argc, char *argv)
{
  unsigned int c=0;
  int i=0;
  while(i<7) {
    if(c != EOF && !feof(stdin))
    {
      c=getchar();
      putchar(c);
    }
    i++;
  }
  while (!feof(stdin))
  {
    c = getchar();
    if(c != EOF)
    {
      putchar((char)((int)c/(int)3));
    }
  }
  return 0;
}
