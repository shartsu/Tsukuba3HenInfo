#include <stdio.h>
#include <stdlib.h>

#define N 10

int count(char x[N]){
	
	int i, len, maxlen;
	len = 0;
	maxlen = 0;
	for(i = 0; x[i] != '\0'; i++) {
		if(x[i] == '1'){
			len += 1;
			if(maxlen < len) {
				maxlen = len;
				}
		} else {
			len = 0;
		}
	}
	
	return maxlen;
}
 
int main(void) {
	int n;
	
	n = count("01011101");
	
	printf("%d\n",n);
	return 0;
}