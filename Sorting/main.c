#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void display(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

////

void bubbleSort(int arr[], int n) {
  int flag;
  for (int i = 0; i < n - 1; i++) {
    flag = 0;
    for (int j = 0; j < n - 1 - i; j++) {

      // largest should sink to the bottom
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        flag = 1;
      }
    }
    // no comp in that pass then break
    if (flag == 0)
      break;
  }

  display(arr, n);
}

void insertionSort(int arr[], int n) {

  int i, j;

  // start from 2nd element
  for (i = 1; i < n; i++) {
    int key = arr[i];

    // keep comapring and shifting to the left
    for (j = i - 1; j >= 0 && arr[j] > key; j--) {
      if (arr[j] > key) {
        arr[j + 1] = arr[j];
      }
    }
    arr[j + 1] = key;
  }

  display(arr, n);
}

void insertionSort2(int arr[], int n) {
  int i, j;

  for (i = 1; i < n; i++) {
    int temp = arr[i];
    for (j = i - 1; j >= 0; j--) {
      if (arr[j] > temp) {
        arr[j + 1] = arr[j];
        arr[j] = temp;
        printf("%d %d \n", i, j);
        continue;
      }
    }
    display(arr, n);
  }
}

void quickSort(int arr[], int n) {}

int main() {
  int arr[5] = {5, 4, 3, 2, 1}, n = (sizeof(arr) / sizeof(int));
  display(arr, n);

  //
  // bubbleSort(arr, n);

  //

  // insertionSort(arr, n);
  //

  insertionSort2(arr, n);
  //
}
