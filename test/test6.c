#include <stdio.h>

int main()
{
  long double seed;
  long double result;
  unsigned int i;

  seed = (long double)1;
  result = (long double)1;
  while (i < 16445)
  {
    seed = seed * ((long double)2);
    i++;
  }
  result = result / seed;
  printf("float is %.16500Lf\n", (long double)result);
  return (0);
}
