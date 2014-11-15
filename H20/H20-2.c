#include <stdio.h>
#define N 5

int a[5][5] ={ {0, 1, 1, 0, 0},
			   {1, 0, 0, 1, 0},
			   {0, 1, 0, 1, 0},
			   {0, 0, 0, 0, 0},
			   {0, 0, 0, 1, 0}};

int maxrank() {
	int i, j, rank, max = 0;

	for(i = 0; i < N; i++) {
		rank = 0;
		for(j = 0; j < N; j++) {
			if(a[j][i] == 1) {
				rank++;
			}
		}

		if(rank > max){
			max = rank;
		}
	}

	return max;
}

int reachable(int start, int goal){

	int i, j, visited[N], checked[N];
	for(i = 0; i < N; i++) {
		visited[i] = 0;
		checked[i] = 0;
	}

	i = start;
	while(1) {
		if(i == goal)
			return 1;

		visited[i] = 1;
		for(j = 0; j < N; j++) {
			if(a[i][j]){
				checked[j] = 1;
			}
		}

		for(j = 0; j < N; j++) {
			if(!visited[j] && checked[j]) {

				return (reachable(j, goal));

				break;
			}
		}

		if((visited[goal]) == 0) {
			return 0;
		}
	}
}

int main()
{
	printf("%d\n", reachable(0, 1));
	printf("%d\n", reachable(0, 2));
	printf("%d\n", reachable(0, 3));
	printf("%d\n", reachable(0, 4));
	printf("%d\n", reachable(1, 0));
	printf("%d\n", reachable(1, 2));
	printf("%d\n", reachable(1, 3));
	printf("%d\n", reachable(1, 4));
	printf("%d\n", reachable(2, 0));
	printf("%d\n", reachable(2, 1));
	printf("%d\n", reachable(2, 3));
	printf("%d\n", reachable(2, 4));
	printf("%d\n", reachable(3, 0));
	printf("%d\n", reachable(3, 1));
	printf("%d\n", reachable(3, 2));
	printf("%d\n", reachable(3, 4));
	printf("%d\n", reachable(4, 0));
	printf("%d\n", reachable(4, 1));
	printf("%d\n", reachable(4, 2));
	printf("%d\n", reachable(4, 3));
	printf("%d", maxrank());
}
