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

  /* �z��ւ̑�� */
  for(i = 0; string[i] != '\0'; i++) {
    string2[i] = string[s-1]; /*s�͈�����č��킹�Ă���*/
    printf("%c", string2[i]);
    s--;
  }
  printf("\n");

  /* �`�F�b�N */
  for(i = 0; string[i] != '\0'; i++) {
    if(string[i] != string2[i]) {
      flag = 1;
    }
  }

  if(flag == 0) {
    printf("�V�����g���[�ł���\n");
	return 0;
  }else{
    printf("�A�V�����g���[�ł���\n");
	return 1;
  }
}

int main()
{
  is_symmetric("colloc");
  is_symmetric("malloc");
  return 0;
}
