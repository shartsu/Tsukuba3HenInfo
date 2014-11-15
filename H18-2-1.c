#include <stdio.h>

char digits[] = "0123456789";

void pr(int x)
{
  if(x >= 10)
    pr(x / 10);

  putchar(digits[x % 10]);
}

void pr2(int x)
{
  int i, d[20];
  i = 0;
  while(x >= 10) {
    d[i] = x % 10;
    x = x / 10;
    i++;
  }

  putchar(digits[x]);
  while(i-- > 0) {
    putchar(digits[d[i]]);
  }
}

int main()
{

  pr(58934);
  printf("\n");
  pr2(931);
  printf("\n");

  return 0;
}
