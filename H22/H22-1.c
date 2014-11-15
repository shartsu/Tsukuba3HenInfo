#include <stdio.h>

int sum1(int n) {
	int s = 0;
	do {
		s = s + n;
	} while (n-- > 0);

	return s;
}

int sum2(int a[], int n)
{
	int j, s = 0;
	for(j = 0; j < n; j++) {
		s += a[j];
	}

	return s;
}

int sum3(int *a, int n)
{
	int i, s = 0;
	for(i = 0; i < n; i++) {
		s += *a++;
	}

	return s;
}

int sum4(int *a, int n)
{
	if(n == 0) {
		return 0;
	} else {
		return *a + sum4(a+1, n-1);
	}
}

int sum5aux(int *a, int n, int acc)
{
	if(n == 0) {
		return acc;
	} else {
		return sum5aux(a+1, n-1, *a+acc);
	}
}

int sum5(int *a, int n)
{
	return sum5aux(a, n, 0);
}

int main()
{
	int n = 10, s;
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	s = sum1(n);
	printf("n = %d  s = %d\n", n, s);

	printf("sum2(a, 10) = %d\n", sum2(a,10));
	printf("sum3(a, 10) = %d\n", sum3(a,10));
	printf("sum4(a, 10) = %d\n", sum4(a,10));
	printf("sum5(a, 10) = %d\n", sum5(a,10));
	return 0;
}