#include <stdio.h>
#include <stdlib.h>

#define N 20

void f(char x[N])
{
	int i;
	for(i = 0; x[i] != '\0'; i++) {
		if(i > 0 && x[i-1] =='1' && x[i] == '1') {
			putchar('0');
		} else {
			putchar(x[i]);
		}
	}
}

int main(void) {

	char x[N];

	f("101110011");

	return 0;
}