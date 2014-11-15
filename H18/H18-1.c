#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;

struct node{
  int item;
  link next;
};

void makeList(link top, int n);
void printList(char *msg, link top);
void rev(link top);
void rev2(link top1, link top2);

int main(int argc, char *argv[])
{
  link top0 = malloc(sizeof(struct node));
  link top1, top2;

  top0->item = -1;
  top0->next = NULL;
  makeList(top0, 4);
  printList("(2) ", top0);
  rev(top0);
  printList("(4) ", top0);

  top1 = malloc(sizeof(struct node));
  top2 = malloc(sizeof(struct node));

  top1->item = top2->item = -1;
  makeList(top1, 4);
  rev2(top1, top2);
  printList("(5) ", top2);
  return 0;
}

void makeList(link top, int n)
{
  int i;
  link x, p = top;

  for(i = 0; i < n; i++) {
    x = malloc(sizeof(struct node));
    x->item = i;
    x->next = NULL;

    p->next = x;
    p = x;
  }
}

void printList(char *msg, link top)
{
  link x = top->next;
  printf("%s", msg);

  while(x != NULL) {
    printf("%d ", x->item);
    x = x->next;
  }

  printf("\n");
}

void rev(link top)
{
  link p = NULL, q, x = top->next;

  while(x != NULL) {
    q = x->next;
    x->next = p;
    p = x;
    x = q;
  }

  top->next = p;
}

void rev2(link top1, link top2)
{
  link p = NULL, x = top1->next, y;

  while(x != NULL){
    y = malloc(sizeof(struct node));
    y->item = x->item;
    y->next = p;
    x = x->next; /* (5a) */
    p = y; /* (5b) */
  }
  top2->next = p;
}
