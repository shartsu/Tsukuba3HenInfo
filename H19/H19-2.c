#include <stdio.h>

char letter[5] = {'a', 'b', 'c', 'd', 'e'};
int count[5] = {0, 0, 0, 0, 0};

void filecheck(FILE *ifp, FILE *ofp)
{
  int i;
  char c;

  while((c = getc(ifp)) != EOF) {
    fputc(c, ofp);
  for(i = 0; i < 5; i++) 
    if(c == letter[i]) count[i]++;
  }
}

int main(int argc, char *argv[])
{
  FILE *fp;
  int i, j;

  if(argc == 1)
    filecheck(stdin, stdout);
  else
    for(i = 1; i < argc; i++)
      if((fp = fopen(argv[i], "r")) == NULL) {
		printf("can't open %s \n", argv[i]);
		return 1;
		
      } else {
		filecheck(fp, stdout);
		fclose(fp);
      }
	  
  for(i = 0; i < 5; i++)
    if(count[i] > 0) {
      for(j = 0; j < count[i]; j++) printf("%c", letter[i]);
      printf("\n");
    }
  return 0;
}
