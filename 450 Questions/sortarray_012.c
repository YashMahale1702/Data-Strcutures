#include <stdio.h>

int main() {
  int a[] = {0, 1, 2, 2, 0, 0, 1, 1};
  int x = 0, y = 0, z = 0, i, n = sizeof(a) / sizeof(int);

  for (i = 0; i < n; i++) {
    if (a[i] == 0)
      x++;
    else if (a[i] == 1)
      y++;
    else if (a[i] == 2)
      z++;
  }

  for (i = 0; i < x; i++) {
    a[i] = 0;
  }

  for (i = x; i < x + y; i++) {
    a[i] = 1;
  }

  for (i = x + y; i < x + y + z; i++) {
    a[i] = 2;
  }

  // print

  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}