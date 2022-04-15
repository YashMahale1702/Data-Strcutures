#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {
  int top;
  int size;
  int *arr;
};

// value should be changed so pointer
void push(struct stack *stk, int data) {
  if (stk->top == stk->size - 1) {
    printf("Stack is Full");
    return;
  }
  stk->top++;
  stk->arr[stk->top] = data;
}

// value should be changed so pointer
int pop(struct stack *stk) {
  if (stk->top == -1) {
    printf("Stack is Full");
    return -1;
  }
  int x = stk->arr[stk->top];
  stk->top--;
  return x;
}

void display(struct stack stk) {
  if (stk.top == -1) {
    printf("No elements to display");
    return;
  }
  printf("Stack elements are :\n");
  for (int i = 0; i <= stk.top; i++) {
    printf("%d ", stk.arr[i]);
  }
  printf("\n");
}

// get the value at a particualr pos from top

int peek(struct stack stk, int pos) {
  if (stk.top == -1)
    return -1;
  else
    return stk.arr[stk.top - pos + 1];
}

int stacktop(struct stack stk) {
  if (stk.top == -1)
    return -1;
  else {
    return stk.arr[stk.top];
  }
}

bool isEmpty(struct stack stk) {
  if (stk.top == -1)
    return true;
  else
    return false;
}

bool isFull(struct stack stk) {
  if (stk.top == stk.size - 1)
    return true;
  else
    return false;
}

int main() {
  struct stack stk;
  stk.size = 5;
  stk.top = -1;
  stk.arr = (int *)malloc(sizeof(int) * stk.size);

  // Array values
  push(&stk, 10);
  push(&stk, 20);
  push(&stk, 30);

  printf("popped : %d \n", pop(&stk));
  printf("Peek at pos %d is %d\n", 1, peek(stk, 1));
  //
  if (isEmpty(stk))
    printf("Is empty\n");
  if (isFull(stk))
    printf("Is Full\n");

  display(stk);
}