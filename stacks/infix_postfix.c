#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// using array
struct stack {
  int size;
  int top;
  char *arr;
};

void push(struct stack *stk, char data) {
  if (stk->top == stk->size - 1)
    return;
  else {
    stk->top++;
    stk->arr[stk->top] = data;
    printf("pushed %c\n", stk->arr[stk->top]);
  }
}

char pop(struct stack *stk) {
  if (stk->top == -1)
    return -1;
  else {
    char x = stk->arr[stk->top];
    stk->top--;
    printf("Popped %c\n", x);
    return x;
  }
}

bool isEmpty(struct stack stk) {
  if (stk.top == -1)
    return true;
  else
    return false;
}

char stacktop(struct stack stk) { return stk.arr[stk.top]; }

int precedence(char ch) {
  if (ch == '+' || ch == '-')
    return 1;
  else if (ch == '/' || ch == '*')
    return 2;
  else
    return 3;
}

bool isOperand(char ch) {
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    return false;
  else
    return true;
}

char *infixtoPostfix(char infix[]) {

  char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));

  // declare a stack

  struct stack stk;
  stk.top = -1;
  stk.size = strlen(infix);
  stk.arr = (char *)malloc(sizeof(char) * stk.size);

  int i = 0, j = 0;

  while (infix[i] != '\0') {
    // if operand
    if (isOperand(infix[i])) {
      postfix[j++] = infix[i++];
    }
    // else  get the precedence of operand
    else {
      // if no element  in the stack push
      if (isEmpty(stk))
        push(&stk, infix[i++]);
      // check the precedence of the cur and the stacktop
      else if (precedence(infix[i]) > precedence(stacktop(stk))) {
        push(&stk, infix[i++]);
      }
      // smaller or equal
      else if (precedence(infix[i]) <= precedence(stacktop(stk))) {
        postfix[j++] = pop(&stk);
      }
    }
  }

  while (!isEmpty(stk)) {
    // pop all the elements
    postfix[j++] = pop(&stk);
  }
  postfix[j] = '\0';

  return postfix;
}

char *infixtoPostfix2(char infix[]) {

  char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));

  // declare a stack

  struct stack stk;
  stk.top = -1;
  stk.size = strlen(infix);
  stk.arr = (char *)malloc(sizeof(char) * stk.size);

  int i = 0, j = 0;

  while (infix[i] != '\0') {
    // if stack is empty just push
    if (isEmpty(stk)) {
      push(&stk, infix[i++]);
    }
    // get the precedence
    else {
      // check the precedence of the cur and the stacktop
      if (precedence(infix[i]) > precedence(stacktop(stk))) {
        push(&stk, infix[i++]);
      }
      // smaller or equal
      else if (precedence(infix[i]) <= precedence(stacktop(stk))) {
        postfix[j++] = pop(&stk);
      }
    }
  }

  while (!isEmpty(stk)) {
    // pop all the elements
    postfix[j++] = pop(&stk);
  }
  postfix[j] = '\0';

  return postfix;
}

int main() {
  // Take a string
  char infix[] = "a+b*c-d/e";

  // Infix to postfix
  char *postfix = infixtoPostfix(infix);

  printf("Postfix expression is :\n");
  for (int i = 0; postfix[i] != '\0'; i++) {
    printf("%c", postfix[i]);
  }

  return 0;
}
