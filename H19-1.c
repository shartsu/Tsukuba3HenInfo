#include <stdio.h>
#include <stdlib.h>


#define QUEUESUZE 100
typedef struct node Node;

struct node {
  char label;
  int value;
  Node *child;
  Node *sister;
};

Node *make_node(char label, int value, Node *parent) {
  Node *newnode;
  newnode = malloc(sizeof(Node));
  newnode->label = label;
  newnode->value = value;
  newnode->child = NULL;
  if(parent != NULL) {
    newnode->sister = parent->child;
    parent->child = newnode;
  }
  return newnode;
}

void print_tree(Node *s, int indent){
  int i;
  if(s == NULL) return;
  for(i = 0; i < indent; i++) printf("*");
  printf("%C : %d\n", s->label, s->value);

  Node *child = s->child;
  while(child != NULL) {
    print_tree(child, indent+1);
    child = child->sister;
  }
}

Node *list[QUEUESUZE];
int p0 = 0;
int p1 = 0;

int is_empty() {
  return (p0 == p1);
}

void enqueue(Node *node) {
  if(p1 == QUEUESUZE) p1 = 0;
  list[p1 ++] = node;
}

Node *dequeue() {
  if(p0 == QUEUESUZE) p0 = 0;
  return list[p0 ++];
}

int question1(Node *node, char key) {
  int value = -1;
  if(node == NULL) return value;
  if(node->label == key) {
    return node->value;
  } else {
    value = question1(node->child, key);
    if(value == -1)
      value = question1(node->sister, key);
    return value;
  }
}

int question2(Node *node, char key) {
  int value = -1;
  p0 = p1 = 0;
  enqueue(node);
  
  do {
    node = dequeue();
    if(node->label == key) {
      value = node->value;
    } else {
      Node *child = node->child;
      while(child != NULL) {
	enqueue(child);
	child = child->sister;
      }
    }
  } while(value == -1 && !is_empty());
  return value;
}

int main() {
  Node *s1, *s2, *s3, *s4, *s5;
  s1 = make_node('A', 10, NULL);
  s2 = make_node('B', 20, s1);
  s3 = make_node('E', 30, s1);
  s4 = make_node('C', 40, s1);
  s5 = make_node('B', 50, s4);
  //  make_node('F', 70, s5);
  make_node('D', 60, s2);
  print_tree(s1, 0);
  printf("value1 = %d\n", question1(s1, 'B'));
  printf("value2 = %d\n", question2(s2, 'B'));
}
