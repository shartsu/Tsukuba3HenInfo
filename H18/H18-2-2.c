#include <stdio.h>

int is_symmetric(char string[])
{
  int i = 0;
  int s = 0;
  int flag = 0;
  char string2[] = "";

  while(string[i] != '\0') {
    putchar(string[i]);
    i++;
    s++;
  }
  printf("\n");

  /* 配列への代入 */
  for(i = 0; string[i] != '\0'; i++) {
    string2[i] = string[s-1]; /*sは一つ下げて合わせている*/
    printf("%c", string2[i]);
    s--;
  }
  printf("\n");

  /* チェック */
  for(i = 0; string[i] != '\0'; i++) {
    if(string[i] != string2[i]) {
      flag = 1;
    }
  }

  if(flag == 0) {
    printf("シンメトリーですよ\n");
	return 0;
  }else{
    printf("アシンメトリーですよ\n");
	return 1;
  }
}

int main()
{
  is_symmetric("colloc");
  is_symmetric("malloc");
  return 0;
}
