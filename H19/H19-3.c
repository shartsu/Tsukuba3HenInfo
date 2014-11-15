#include <stdio.h>

struct lettercount{
  char letter;
  int count;
} letterdata[] = {
  {'a', 0},
  {'b', 0},
  {'c', 0},
  {'d', 0},
  {'e', 0},
};
 
void filecheck(FILE *ifp, FILE *ofp)
{
  int i;
  char c;

  while((c = getc(ifp)) != EOF) {
    fputc(c, ofp);
  for(i = 0; i < 5; i++) 
    if(c == letterdata[i].letter) letterdata[i].count++;
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
    if(letterdata[i].count > 0) {
      for(j = 0; j < letterdata[i].count; j++)
	printf("%c", letterdata[i].letter);
      printf("\n");
    }
  return 0;
}
