#include <stdio.h>

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int a[] = {-25, 14, -75, 12, -63, 56, -12};
  int i = 0, n = sizeof(a) / sizeof(int);
  int j = n - 1;

  while (i < j) {
    while (a[i] < 0)
      i++;
    while (a[j] >= 0)
      j--;
    if (i < j)
      swap(&a[i], &a[j]);
  }

  // print
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
}