
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
} *front = NULL, *rear = NULL;

void Enqueue(int data) {
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  if (!newnode) {
    printf("Queue is Full\n");
  } else {
    // insert rear
    printf("Inserted\n");
    newnode->data = data;
    newnode->next = NULL;
    if (front == NULL)
      front = rear = newnode;
    rear->next = newnode;
    rear = newnode;
  }
}

int Dequeue() {
  int x = -1;
  if (front == NULL)
    printf("Queue is empty\n");
  else {
    struct Node *p = front;
    front = front->next;
    x = p->data;
    free(p);
  }
  return x;
}

void display() {
  struct Node *p;
  if (front == NULL) {
    printf("Queue is empty\n");
  }

  for (p = front; p != NULL; p = p->next) {
    printf("%d ", p->data);
  }
  printf("\n");
}

int main() {

  // Array values
  Enqueue(10);
  Enqueue(20);
  Enqueue(30);
  Enqueue(40);
  Enqueue(100);

  // dequeue
  Dequeue();
  Dequeue();

  // display
  display();
}