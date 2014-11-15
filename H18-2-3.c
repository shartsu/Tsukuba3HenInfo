#include <stdio.h>

int f(int m, int n)
{
  int a, b, x[50];

  x[0] = 1;
  for(a = 1; a <= m; a++) {
    x[a] = 0;
    for(b = a; b > 0; b--) {
      x[b] = x[b-1] + x[b];
      printf("x[%d] =  %d\n", b, x[b]);
    }
    printf("---\n");
  }
  return x[n];
}

int g(int m, int n)
{
  int a, b, x[50];

  for(b = 0; b <= n; b++)
    x[b] = 1;
  for(a = 1; a <= m; a++){
    for(b = a-1; b >= 1; b--) {
      x[b] = x[b-1] + x[b];
      printf("x[%d] =  %d\n", b, x[b]);
    }
    printf("---\n");
  }

  return x[n];
}

int main()
{
  printf("%d \n",f(7,6));
  printf("%d \n",g(7,6));

  return 0;
}
