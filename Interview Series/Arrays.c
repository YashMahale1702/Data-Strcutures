#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[5] = {1, 3, 7, 9, 2}, i, j, target, cur = 0, n = 5;
  scanf("%d", &target);

  for (i = 0; i < n - 1; i++) {
    // remainder
    cur = target - arr[i];
    for (j = i + 1; j < n; j++) {
      if (cur == arr[j]) {
        printf("Found the indices : %d %d", i, j);
        return 0;
      }
    }
  }
  printf("Indices not found.\n");
  return 0;
}