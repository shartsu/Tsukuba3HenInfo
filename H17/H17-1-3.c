#include <stdio.h>

int ccount(char str[], char c){
  int i;
  int count = 0;

  for(i = 0; str[i] != '\0' ; i++) {
    if(str[i] == c) {
      count++;
    }
  }

  return count;
}

int main()
{
  int d;
  char str[] = "hello";

  d = ccount(str, 'l');
  printf("%d\n", d);

  return 0;
}
