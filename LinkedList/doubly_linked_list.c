#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *prev;
  int data;
  struct Node *next;
};

struct Node *insert_front(struct Node *first, int data) {
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->next = newnode->prev = NULL;
  newnode->data = data;

  if (first == NULL)
    return newnode;
  else {
    struct Node *p;
    for (p = first; p->next != NULL; p = p->next)
      ;
    newnode->prev = p;
    p->next = newnode;

    return first;
  }
}

struct Node *insert_rear(struct Node *first, int data) {
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->next = newnode->prev = NULL;
  newnode->data = data;

  if (first == NULL)
    return newnode;
  else {
    newnode->next = first;
    first->prev = newnode;
    first = newnode;

    return first;
  }
}

void display(struct Node *first) {
  if (first == NULL)
    printf("No elements\n");
  else {
    struct Node *p;
    for (p = first; p != NULL; p = p->next) {
      printf("%d ", p->data);
    }
    printf("\n");
  }
}

struct Node *reverse(struct Node *first) {
  if (first == NULL)
    return first;
  else {
    struct Node *p, *temp;
    for (p = first; p != NULL;) {

      // swap the pointers prev and next
      temp = p->next;
      p->next = p->prev;
      p->prev = temp;
      p = p->prev;

      if (p->next == NULL)
        first = p;
    }

    return first;
  }
}

int main() {
  struct Node *first = NULL;
  int A[] = {10, 20, 30, 40, 50}, n = sizeof(A) / sizeof(int);

  // create a doubly linked list
  for (int i = 0; i < n; i++) {
    first = insert_front(first, A[i]);
  }

  // Insert rear
  //   first = insert_rear(first, 20);

  // reverse
  first = reverse(first);

  // display
  display(first);
}