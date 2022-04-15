#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>

struct Node {
  struct Node *lchild;
  int data;
  struct Node *rchild;
};

// ? Note : dynamic array which stores address values so **
// ? one * for dynamic array and the other for the type struct node *
//? Only Inserting and returning the values chages the type rest remains same

struct Queue {
  int size;
  int front, rear;
  struct Node **arr;
};

void createQueue(struct Queue *que, int size) {
  que->size = size;
  que->front = que->rear = -1;
  que->arr = (struct Node **)malloc(sizeof(struct Node *) * que->size);
}

// value should be changed so pointer
void Enqueue(struct Queue *que, struct Node *data) {
  if (que->rear == que->size - 1) {
    printf("Queue is Full");
    return;
  }
  que->rear++;
  que->arr[que->rear] = data;
}

// value should be changed so pointer
struct Node *Dequeue(struct Queue *que) {
  if (que->front == que->rear) {
    printf("Queue is Empty");
    return NULL;
  }
  que->front++;
  return que->arr[que->front];
}

bool isEmpty(struct Queue que) { return que.rear == que.front ? true : false; }

void display(struct Queue que) {
  if (que.front == que.rear) {
    printf("No elements to display");
    return;
  }
  printf("Queue elements are :\n");
  for (int i = que.front + 1; i <= que.rear; i++) {
    printf("%p ", que.arr[i]);
  }
  printf("\n");
}