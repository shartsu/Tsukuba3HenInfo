#include <stdio.h>
#define N 7

int data[] = {8, 10, 0, 10, 6, 5, 2};

void f(){
	int i, j, k, B[11];
	for(k = 0; k <= 10; k++)
		B[k] = 0;

	for(i = 0; i < N; i++)
		B[data[i]] = B[data[i]] + 1;

	i = 0;
	for(k = 0; k <= 10; k++) {
		if(B[k] > 0) {
			for(j = 0; j < B[k]; j++) {
				data[i] = k;
				i++;
			}
		}
	}


	for(i = 0; i < N; i++) {
		printf("%d ",data[i]);
	}
	printf("\n");
}

int main(void)
{
	f();

	return 0;

}
