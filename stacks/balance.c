#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

bool isBalanced(char *str) {
  struct stack stk;
  stk.top = -1;
  stk.size = strlen(str);
  stk.arr = (char *)malloc(sizeof(char) * stk.size);
  printf("%d \n", stk.size);

  // until null char
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '(') {
      push(&stk, str[i]);
    } else if (str[i] == ')') {
      // check if the stack is empty
      if (isEmpty(stk))
        return false;
      pop(&stk);
    }
  }

  if (isEmpty(stk))
    return true;
  else
    return false;
}

bool isMatchingPair(char character1, char character2) {
  if (character1 == '(' && character2 == ')')
    return 1;
  else if (character1 == '{' && character2 == '}')
    return 1;
  else if (character1 == '[' && character2 == ']')
    return 1;
  else
    return 0;
}

bool isBalanced2(char *str) {
  struct stack stk;
  stk.top = -1;
  stk.size = strlen(str);
  stk.arr = (char *)malloc(sizeof(char) * stk.size);
  printf("%d \n", stk.size);
  char popped;

  // until null char
  for (int i = 0; str[i] != '\0'; i++) {
    printf("%d\n", i);
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      push(&stk, str[i]);
    } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {

      // check the popped elements with the current element
      popped = pop(&stk);
      if (isMatchingPair(popped, str[i])) {
        continue;
      } else {
        return false;
      }
    }
  }

  if (isEmpty(stk))
    return true;
  else
    return false;
}

int main() {
  // Take a string
  char str[] = "{[(a+b)*(c+d)]}";

  // determine the function of isbalanced
  bool checkIsbalanced = isBalanced2(str);
  checkIsbalanced ? printf("Expression is Balanced\n")
                  : printf("Expression is Not balanced\n");
}
