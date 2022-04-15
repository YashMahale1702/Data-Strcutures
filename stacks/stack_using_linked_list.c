#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *push(struct Node *top, int data) {
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

  // if system heap is full
  if (newnode == NULL)
    printf("stack Full");

  // else
  else {
    newnode->data = data;
    newnode->next = top;
    top = newnode;
  }
  return top;
}

struct Node *pop(struct Node *top) {
  int x = -1;
  if (top == NULL)
    printf("stack empty\n");
  else {
    struct Node *p = top;
    top = top->next;
    printf("popped %d\n", x = p->data);
    free(p);
  }
  return top;
}

void display(struct Node *top) {
  if (top == NULL) {
    printf("Stack is empty\n");
    return;
  }
  for (struct Node *p = top; p != NULL; p = p->next) {
    printf("%d ", p->data);
  }
  printf("\n");
}

int main() {
  struct Node *top = NULL;
  //

  // Array values
  top = push(top, 10);
  top = push(top, 20);
  top = push(top, 30);

  top = pop(top);
  //   printf("Peek at pos %d is %d\n", 1, peek(top, 1));

  display(top);
}