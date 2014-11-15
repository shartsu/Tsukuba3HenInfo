#include <stdlib.h>
#include <stdio.h>

#define Ni1 0

typedef struct cell0 *c0ptr;
typedef struct cell1 *c1ptr;

struct cell0 {
  c0ptr left;
  c1ptr right;
};

struct cell1 {
  int data;
  c1ptr next;
};

c0ptr mkMat(int m, int n, int data[]){
  int i=0, j=0, k=0;
  c0ptr c0, prev0, mat;
  c1ptr c1, prev1;

  for (i = 0; i < m; i++) {
    c0 = malloc(sizeof(struct cell0));

    if (i == 0) {
      mat = c0;
	} else {
      prev0 -> left = c0;
	}

    for (j = 0; j < n; j++) {
      c1 = malloc(sizeof(struct cell1));
      if (j == 0) {
        c0 -> right = c1;
      } else {
        prev1 -> next = c1;
		c1 -> data = data[k++];
		prev1 = c1;
      }
    }

    prev1->next = Ni1;
    prev0 = c0;
  }

  prev0 -> left = Ni1;
  return mat;
}


void printMat(c0ptr mat) {
  c0ptr c0;
  c1ptr c1;

  for (c0 = mat; c0 != Ni1; c0 = c0->left) {
    for(c1 = c0->right; c1 != Ni1; c1 = c1->next) {
      printf("%d", c1->data);
    }
  }
  printf("\n");
}

int f0(c0ptr mat) {
  c0ptr c0;
  c1ptr c1;
  int n;

  for(c0 = mat; c0 != Ni1; c0 = c0->left) {
  	for(c1 = c0->right; c1 != Ni1; c1 = c1->next) {
      n++;
  	}
  }

  return n;
}

void f1(c0ptr m0, c0ptr m1){
  c0ptr c01, c02;
  c1ptr c11, c12;

  for(c01 = m0, c02 = m1; c01 != Ni1;
      c01 = c01->left, c02 = c02->left) {
	  	for(c11 = c01->right, c12 = c02->right; c11 != Ni1;
		c11 = c11->next, c12 = c12->next) {
			c11->data += c12->data;
		}
      }
}

void f2(c0ptr m0, c0ptr m1) {
  c0ptr c01, c02;
  c1ptr c11, c12;

  for(c01 = m0, c02 = m1;
      c01 != Ni1;
      c01 = c01->left, c02 = c02->left) {

    for(c11 = c01->right; c11 != Ni1; c11 = c11->next) {
		if(c11->next == Ni1){
			c11->next = c02->right;
			break;
		}
    }
      }
}

void f3(c0ptr m0, c0ptr m1) {
  c0ptr c0;

  for (c0 = m0; c0 != Ni1; c0 = c0->left) {
  	if(c0->left == Ni1) {
		c0->left = m1;
		break;
  	}
  }
}

int main(void) {
  int data0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  c0ptr m0, m1, m2, m3, m4;

  m0 = mkMat(2, 2, data0); printMat(m0); /* (X) */

  //m1 = mkMat(3, 3, data0); printMat(m1); /* (1) */
  //printf("f0(m1)=%d\n", f0(m1));         /* (2) */
  //f1(m0, m0); printMat(m0);             /* (3) */
  //m2 = mkMat(3, 3, data0);
  //f2(m1, m2); printMat(m1);              /* (4) */
  //m3 = mkMat(3, 3, data0);
  //m4 = mkMat(3, 3, data0);
  //f3(m3, m4); printMat(m3);              /* (5) */
}


