#include <stdio.h>
#include <stdlib.h>

void print_array(int a[], int n) {
	int i;
	for(i = 0; i < n-1; i++) {
		printf("%d,", a[i]);
	}
	
	printf("%d\n", a[n-1]);
}

void sort(int a[], int n) {
	int i, j, tmp;
	for(i = 1; i < n; i++) {
		for(j = i; j > 0 && a[j-1] > a[j]; j--) {
			tmp = a[j];
			a[j] = a[j-1];
			a[j-1] = tmp;
			print_array(a, n);
		}
	}
}

void check_swap(int a[], int i, int j) {
	int tmp;
	if(a[i] > a[j] ){
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	print_array(a, 4);
}

void sort4(int a[])
{
	check_swap(a, 0, 3);
	check_swap(a, 1, 2);
	check_swap(a, 2, 3);
	
	check_swap(a, 0, 1);
	check_swap(a, 1, 2);
	
}

int main()
{
	int a[5] = {2, 1, 5, 4, 3};
	int b[5] = {3, 5, 2, 1, 4};
	int c[5] = {1, 2, 3, 4, 5};
	int d[5] = {5, 4, 3, 2, 1};
	
	int a4[5] = {1, 4, 2, 3};,
	
	sort(d, 5);
	
	sort4(a4);
	
	return 0;
}