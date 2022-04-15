#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue {
  int size;
  int front, rear;
  int *arr;
};

// value should be changed so pointer
void Enqueue(struct Queue *que, int data) {
  if (que->rear == que->size - 1) {
    printf("Queue is Full");
    return;
  }
  que->rear++;
  que->arr[que->rear] = data;
}

// value should be changed so pointer
int Dequeue(struct Queue *que) {
  if (que->front == que->rear) {
    printf("Queue is Empty");
    return -1;
  }
  que->front++;
  int x = que->arr[que->front];
  return x;
}

void display(struct Queue que) {
  if (que.front == que.rear) {
    printf("No elements to display");
    return;
  }
  printf("Queue elements are :\n");
  for (int i = que.front + 1; i <= que.rear; i++) {
    printf("%d ", que.arr[i]);
  }
  printf("\n");
}

int queueFront(struct Queue que) {
  if (que.front == -1)
    return -1;
  else {
    return que.arr[que.front];
  }
}

int queueRear(struct Queue que) {
  if (que.rear == -1)
    return -1;
  else {
    return que.arr[que.rear];
  }
}

bool isEmpty(struct Queue que) {
  if (que.front == que.rear)
    return true;
  else
    return false;
}

bool isFull(struct Queue que) {
  if (que.rear == que.size - 1)
    return true;
  else
    return false;
}

int main() {
  struct Queue que;
  que.size = 5;
  que.front = que.rear = -1;
  que.arr = (int *)malloc(sizeof(int) * que.size);

  // Array values
  Enqueue(&que, 10);
  Enqueue(&que, 20);
  Enqueue(&que, 30);

  printf("Dequeued : %d \n", Dequeue(&que));
  //   printf("Peek at pos %d is %d\n", 1, peek(que, 1));
  //
  if (isEmpty(que))
    printf("Is Empty\n");
  if (isFull(que))
    printf("Is Full\n");

  display(que);
}