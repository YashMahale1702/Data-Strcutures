#include <stdio.h>

// *left rotate
int main() {
  int a[] = {-25, 14, -75, 12, -63, 56, -12}, n = sizeof(a) / sizeof(int);
  int i = 0, temp = a[0];

  for (i = 0; i < n - 2; i++) {
    a[i] = a[i + 1];
  }

  a[n - 1] = temp;

  // print
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
}
