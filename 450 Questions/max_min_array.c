#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[] = {10, 15, 22, 2, -25, 100, 84, 32, 5, 6, 5600000};
  int i, length = sizeof(arr) / sizeof(int);
  int min = arr[0], max = arr[0];

  for (i = 1; i < length; i++) {
    // current is smaller
    if (arr[i] < min) {
      min = arr[i];
      //   continue;
    }
    // greater
    else if (arr[i] >= max) {
      max = arr[i];
    }
  }

  printf("max : %d min : %d\n", max, min);
  return 0;
}