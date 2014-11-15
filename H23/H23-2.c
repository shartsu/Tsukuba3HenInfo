#include <stdio.h>

#define N 100
#define MAX 10000;
	int a[N][N];
	int checked[N];
	int d[N];
	int p[N];
	int howairu = 0;

int find_min(int n) {
	int min_node = -1;
	int min_dist = 10000;
	int i;

	int flag = 0;
	int j = 10000;
	for(i = 0; i < n; i++) {
		if(checked[i] == 0 && d[i] < 10000) {
			if(min_dist > d[i]) {
				min_dist = d[i];
				if(j > i) {
					j = i;
					flag = 1;
				}
			}
		}
	}

	if(flag != 0) {
		return j;
	} else {
		return min_node;
	}
}

int f(int start, int end, int n) {
	int node, i;
	for(i = 0; i < n; i++) {
		checked[i] = 0;
		d[i] = 10000;
		p[i] = -1;
	}

	node = start;
	checked[node] = 1;
	d[node] = 0;

	while(1) {
		howairu++;
		for(i = 0; i < n; i++) {
			if((! checked[i]) && (d[i] > d[node] + a[node][i])) {
				d[i] = d[node] + a[node][i];
				p[i] = node;
			}
		}

		for(i = 0; i < n; i++) {
			printf("d[%d] = %d\n", i, d[i]);
		}

		if((node = find_min(n)) == -1) return -1;
		checked[node] = 1;
		if(node == end) return d[node];
	}
}

int main()
{
	int res;
	int i;

	a[0][0] = MAX;
	a[0][1] = 10;
	a[0][2] = 15;
	a[0][3] = 40;
	a[0][4] = MAX;

	a[1][0] = 10;
	a[1][1] = MAX;
	a[1][2] = 10;
	a[1][3] = MAX;
	a[1][4] = 50;

	a[2][0] = 15;
	a[2][1] = 10;
	a[2][2] = MAX;
	a[2][3] = 30;
	a[2][4] = 20;

	a[3][0] = 40;
	a[3][1] = MAX;
	a[3][2] = 30;
	a[3][3] = MAX;
	a[3][4] = 20;

	a[4][0] = MAX;
	a[4][1] = 50;
	a[4][2] = 20;
	a[4][3] = 20;
	a[4][4] = MAX;

	res = f(0, 4, 5);

	printf("res = %d\n", res);
	for(i = 0; i < 5; i++) {
		printf("p[%d] = %d\n", i, p[i]);
	}
	printf("while = %d\n",howairu);
}

