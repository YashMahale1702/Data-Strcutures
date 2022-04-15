// * Reverse the array

#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  int i, j, length = sizeof(arr) / sizeof(int), temp;

  for (i = 0, j = length - 1; i <= j; i++, j--) {
    // swap here
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }

  for (i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
}