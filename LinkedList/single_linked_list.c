#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
  int data;
  struct Node *next;
};

int countLength(struct Node *);

struct Node *create(struct Node *first, int A[], int n) {
  struct Node *p, *last;
  int i;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++) {
    // create a new node
    p = (struct Node *)malloc(sizeof(struct Node *));
    p->data = A[i];
    p->next = NULL;

    // link the last node to the new node
    last->next = p;
    last = last->next;
  }

  return first;
}

struct Node *insert_rear(struct Node *first, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  // if there are no current nodes
  if (first == NULL)
    return newNode;

  // if there are nodes trevale to the last node
  else {
    struct Node *p;
    for (p = first; p->next != NULL; p = p->next)
      ;
    p->next = newNode;

    return first;
  }
}

struct Node *insert_front(struct Node *first, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  // if there are no current nodes
  if (first == NULL)
    return newNode;

  // if there are nodes trevale to the last node
  else {
    newNode->next = first;
    first = newNode;
    return first;
  }
}

void display(struct Node *first) {
  struct Node *p;
  for (p = first; p != NULL; p = p->next) {
    printf("%d ", p->data);
  }
  printf("\n");
}

int countLength(struct Node *first) {
  int count = 0;
  struct Node *p;
  for (p = first; p != NULL; p = p->next)
    count++;

  return count;
}

int sum(struct Node *first) {
  int sum = 0;
  struct Node *p;
  for (p = first; p != NULL; p = p->next)
    sum += p->data;

  return sum;
}

int max(struct Node *first) {
  int max = INT_MIN;
  struct Node *p;
  for (p = first; p != NULL; p = p->next) {
    if (p->data > max) {
      max = p->data;
    }
  }

  return max;
}

int min(struct Node *first) {
  int min = INT_MAX;
  struct Node *p;
  for (p = first; p != NULL; p = p->next) {
    if (p->data < min) {
      min = p->data;
    }
  }

  return min;
}

void search(struct Node *first, int key) {
  struct Node *p;
  int i = 0;
  for (p = first; p != NULL; p = p->next, i++) {
    if (key == p->data) {
      printf("Key found at %d and element is %d\n", i, p->data);
      return;
    }
  }
  printf("Key Not found \n");
}

struct Node *searchMoveToFront(struct Node *first, int key) {
  struct Node *cur, *prev = NULL;
  int i = 0;
  for (cur = first; cur != NULL; prev = cur, cur = cur->next, i++) {
    if (key == cur->data) {
      // change the pointer
      prev->next = cur->next;
      //
      cur->next = first;
      first = cur;
      //
      printf("Key found at %d and element is %d\n", i, cur->data);
      return first;
    }
  }
  printf("Key Not found \n");
  return first;
}

struct Node *insert_sorted_list(struct Node *first, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)), *p, *q;
  newNode->data = data;
  newNode->next = NULL;

  // If there are no nodes
  if (first == NULL)
    return newNode;

  // If it is the first position
  if (first->data > data) {
    newNode->next = first;
    first = newNode;
    return first;
  }

  // else
  for (p = first; p->data < data; q = p, p = p->next)
    ;
  newNode->next = q->next;
  q->next = newNode;
  return first;
}

struct Node *insert_pos(struct Node *first, int index, int data) {
  if (index < 0 || index > countLength(first)) {
    printf("Invalid index");
    return first;
  } else {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)), *p;
    newNode->next = NULL;
    newNode->data = data;
    // if it is 0
    if (index == 0) {
      newNode->next = first;
      first = newNode;
    }

    // In-between index
    else {

      for (int i = 0; i < index - 1; i++, p = p->next)
        ;
      newNode->next = p->next;
      p->next = newNode;
    }

    return first;
  }
}

struct Node *delete_pos(struct Node *first, int index) {
  if (index < 0 || index > countLength(first)) {
    printf("Invalid index");
  } else {
    struct Node *p = first, *q = first;
    if (first == NULL)
      return first;

    if (index == 0) {
      p = first;
      first = first->next;
      free(p);
      return first;
    }

    // In-between index
    else {
      p = q = first;
      for (int i = 0; i < index; i++, q = p, p = p->next)
        ;
      q->next = p->next;
      free(p);
    }
  }
  return first;
}

void check_if_sorted(struct Node *first) {
  struct Node *p;
  for (p = first; p->next->next != NULL; p = p->next) {
    if (p->data > p->next->data) {
      printf("Not sorted.\n");
      return;
    }
  }
  printf("Sorted.\n");
  return;
}

void delete_duplicates(struct Node *first) {
  struct Node *p = first->next, *q = first;

  while (p != NULL) {
    if (p->data == q->data) {
      q->next = p->next;
      free(p);
      p = q->next;

    } else {
      q = p;
      p = p->next;
    }
  }
}

struct Node *reverse(struct Node *first) {
  struct Node *p, *q, *r;
  p = first;
  r = NULL;
  q = NULL;

  while (p != NULL) {
    // slide the pointers
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }

  first = q;
  return first;
}

int main() {
  //
  struct Node *first = NULL;
  int A[] = {10, 10, 20, 30, 40, 50, 50, 50, 50, 120},
      n = sizeof(A) / sizeof(int);

  // *Insert the given array into the list
  for (int i = 0; i < n; i++) {
    first = insert_rear(first, A[i]);
  }

  // Create a linked list
  // first = create(A, n, first);

  // *Count , sum, min, max ,search
  printf("Sum is %d\n", sum(first));
  printf("Count is %d\n", countLength(first));
  printf("max is %d\n", max(first));
  printf("min is %d\n", min(first));

  // Linaer search
  search(first, 10);

  // *optimized search
  // first = searchMoveToFront(first, 50);

  // Insert at position
  // first = insert_pos(first, 10, 143);

  // Insert in a sorted list
  first = insert_sorted_list(first, 15);
  first = delete_pos(first, 2);

  // check if sorted
  check_if_sorted(first);

  // delete duplicates
  delete_duplicates(first);

  // reverse
  first = reverse(first);

  // Display the list
  printf("\n");
  display(first);
}