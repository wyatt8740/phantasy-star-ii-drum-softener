#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv)
{
  double multiplier=0.5;
  if(argc > 1)
  {
    double d=atof(argv[1]);
    if(d > 0.0) /* basically not zero */
    {
      multiplier=d;
    }
  }
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
      putchar((char)(int)((double)c * (double)multiplier));
    }
  }
  return 0;
}
