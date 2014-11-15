#include <stdio.h>

int search1(int data[], int value, int left, int right){
	
	int i;
	for (i = left; i <= right; i++) {
		if (value == data[i]) {
			return i;
		}
	}
	
	return -1;
}

int search2(int data[], int value, int left, int right) {

	while(right >= left) {
		int middle = (right + left)/2;
		
		printf("middle = %d\n",middle);
		
		if(value == data[middle])
			return middle;
		if(value < data[middle])
			right = middle - 1;
		else
			left = middle + 1;
	}
	
	return -1;
}

main(int argc, char** argv)
{
	int x[] = {1, 2, 3, 4, 5, 6};
	printf("%d\n", search1(x, 3, 0, 5));
	printf("%d\n", search2(x, 3, 0, 5));
	
	return 0;
}