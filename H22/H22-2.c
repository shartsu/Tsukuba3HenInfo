#include <stdio.h>
#include <stdlib.h>

void prefixsum(int m, int n, int a[], int c[])
{
	int i;
	
	/* ゼロクリア */
	for(i = 0; i < m; i++) {
		c[i] = 0;
	}
	
	/* 出現頻度の計算 */
	for(i = 0; i < n; i++) {
		c[a[i]]++;
	}
	
	/* プレフィックスサムの計算 */ 
	for(i = 1; i < m; i++) {
		c[i] = c[i] + c[i - 1];
	}
	
}

void sort(int m, int n, int a[], int b[])
{
	int i, *c;
	int j;
	
	c = malloc(m * sizeof(*c));
	
	prefixsum(m, n, a, c);
	
	
	for(i = n-1; i >= 0; i--) {
		
		b[c[a[i]] - 1] = a[i];
		
		for(j = b[c[a[i]] - 1]; j > 0; j--) {
			if(b[j] == 0) {
				b[j] = b[j+1];
			}
		}
	}
	
	free(c);
}
	
	
int main()
{
	int a[] = {1,5,2,7,5,5,4};
	int c[8];
	int b[7];
	int m = 8;
	int n = 7;
	int i;
	
	
	prefixsum(m, n, a, c);

	
	for(i = 0; i < m; i++) {
		printf("c[%d] = %d\n", i, c[i]);
	}

	sort(m, n, a, b);
		
	for(i = 0; i < n; i++) {
		printf("b[%d] = %d\n", i, b[i]);
	}
	
	return 0;
}