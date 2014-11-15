#include <stdio.h>
#include <stdlib.h>

#define N 10

void pascal1()
{
	int pas[10][10], i, j;

	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			pas[i][j] = -1;

	pas[0][0] = 1;
	pas[1][0] = pas[1][1] = 1;

	for(i = 2; i < N; i++) {
		pas[i][0] = 1;
		for(j = 1; j < i; j++) {
			pas[i][j] = pas[i-1][j-1] + pas[i-1][j];
		}
		pas[i][i] = 1;
	}
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++)
			printf("%3d ", pas[i][j]);
		printf("\n");
	}
}

void pascal2()
{
	int *pas[N], i, j;
	int s = 0;

	for(i = 0; i < N; i++) {
		pas[i] = (int *)malloc(sizeof(int)*(i+1));
		s += 4*(i+1);
	}

	printf("%d ", s);

	pas[0][0] = 1;
	pas[1][0] = pas[1][1] = 1;

	for(i = 2; i < N; i++) {
		pas[i][0] = pas[i][i] = 1;
		for(j = 1; j <i; j++) {
			pas[i][j] = pas[i-1][j-1] + pas[i-1][j];
		}
	}

	for(i = 0; i < N; i++) {
		for(j = 0; j < i+1; j++)
			printf("%3d ", pas[i][j]);
		printf("\n");
	}
}

struct entry {
	int value;
	struct entry * next;
};

struct entry *newEntry(int value, struct entry *next)
{
	struct entry *e = (struct entry*)malloc(sizeof(struct entry));
	e->value = value;
	e->next = next;
	return e;
}

void pascal3()
{
	struct entry *pas[N], *p, *q;
	int i, j;

	pas[0] = newEntry(1, NULL);
	pas[1] = newEntry(1, newEntry(1, NULL));

	for(i = 2; i < N; i++) {
		p = pas[i-1];
		q = pas[i] = newEntry(1, NULL);
		for(j = 1; j < i; j++) {
			q->next = newEntry(p->value + p->next->value, NULL);
			p = p->next;
			q = q->next;
		}
		q->next = newEntry(1, NULL);
	}

	for(i = 0; i < N; i++) {
		for(p = pas[i]; p->next != NULL; p = p->next) {
			printf("%3d ", p->value);
		}
		printf("%3d \n", p->value);
	}
}

int main(){

	pascal2();
	pascal3();

	return 0;
}