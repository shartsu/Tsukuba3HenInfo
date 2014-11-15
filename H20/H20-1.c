#include <stdio.h>
#define TRUE 1
#define FALSE 0

int func(int b, int n) {
	
	if(n == 0) {
		return 1;
	} else {
		return b * func(b, n-1);
	}
}

int iseven(int n) {
	if((n % 2) == 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int square(int n) {
	return n * n;
}

int halve(int n) {
	return n / 2;
}

int func2(int b, int n) {

	if(n == 0) {
		return 1;
	} else if(iseven(n) == TRUE) {
		return func2(square(b), halve(n));
	} else {
		return b * func(b, n-1);
	}
}

int main()
{

	printf("%d\n", func(5, 4));
	printf("%d\n", func2(5, 4));

	return 0;
}