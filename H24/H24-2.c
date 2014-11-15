#include <stdio.h>
#define MAXVAL 1000;

void print_array(int i, int s, int ok[]) {
  int j;
  printf("i = %d: ", i);
  for(j = 0; j <= s; j++) {
    if(ok[j] == 1) printf("%d ", j);
  }

  printf("\n");
}

int f(int s, int n, int p[]) {
  int i, j;
  int ok[1000];
  ok[0] = 1;

  for(j = 1; j <= s; j++)
    ok[j] = 0;
  for(i = 0; i < n; i++) {
    print_array(i, s, ok);
    for(j = s; j > 0; j--) {
      if((j >= p[i]) && (ok[j-p[i]]))
		ok[j] = 1;
      /*if(ok[s] == 1) return 1;  3”Ô‚Ì“š‚¦ */
    }
  }

  return (ok[s]);
}

int main() {
  int s, n;
  int p[] = {4, 2, 7, 5, 9};
  n = 5;
  s = 13;
  printf("answer = %d\n", f(s, n, p));
  printf("01:26\n");
}
