#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 20

int toInt(char x[N])
{
	int i, num;
	num = 0;
	for(i = 0; x[i] != '\0'; i++){
		if(x[i] == '1'){
			num += pow(2,(strlen(x) - (i+1)));
			printf("%c | %d\n",x[i] , num);
		}
	}

	return num;
}

int main(void) {
	int n;

	n = toInt("1101");

	printf("%d\n",n);

	return 0;
}