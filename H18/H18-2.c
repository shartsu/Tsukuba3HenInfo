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

/* 2”Ô */ 

int is_symmetric(char string[])
{
  int i = 0;
  int s = 0;
  int flag = 0;
  int len;
  char string2[] = "";

  while(string[i] != '\0') {
    putchar(string[i]);
    i++;
    s++;
  }
  printf("\n");

  // é…åˆ—ã¸ã®ä»£å…¥
  for(i = 0; string[i]!= '\0'; i++) {
    string2[i] = string[s-1]; //sã¯ä¸€ã¤ä¸‹ã’ã¦åˆã‚ã›ã¦ã„ã‚‹
    printf("%c", string2[i]);
    s--;
  }
  printf("\n");

  // ãƒã‚§ãƒƒã‚¯
  for(i = 0; string[i]!= '\0'; i++) {
    if(string[i] != string2[i]) {
      flag = 1;
    }
  }

  if(flag == 0) {
    printf("ƒVƒ“ƒƒgƒŠ[‚Å‚·‚æ\n");
    return 0;
  }else{
    printf("ƒAƒVƒ“ƒƒgƒŠ[‚Å‚·‚æ\n");
    return 1;
  }
}

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
  int i;

  for(b = 0; b <= n; b++)
    x[b] = 1;
  for(a = 1; a <= m; a++){
    //    for(b = 1; b <= a-1; b++){
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
  int r;

  pr(58934);
  printf("\n");
  pr2(931);
  printf("\n");

  is_symmetric("abcba");

  printf("%d \n",f(7,6));
  printf("%d \n",g(7,6));

  return 0;
}
