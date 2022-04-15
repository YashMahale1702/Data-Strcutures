#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p = malloc(sizeof(int) * 5);
  int i;
  for (i = 0; i < 5; i++) {
    p[i] = i + 5;
  }

  for (i = 0; i < 5; i++) {
    printf("%d ", p[i]);
  }
}