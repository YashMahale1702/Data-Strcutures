#include <stdio.h>
#include <stdlib.h>

struct Array {
  int A[10];
  int size;   // Determines the total capacity of an array
  int length; // Current length
};

void display(struct Array arr) {
  int i;
  printf("Elements are : \n");
  for (i = 0; i < arr.length; i++)
    printf("%d ", arr.A[i]);
  printf("\n");
  printf("Length : %d  Size : %d\n", arr.length, arr.size);
}

void append(struct Array *arr, int x) {
  if (arr->length < arr->size) {
    arr->A[arr->length] = x;
    arr->length++;
    printf("Appended %d\n", x);
    return;
  }
  printf("Not appended.\n");
}

void insert(struct Array *arr, int index, int x) {
  int i;
  if (index >= 0 && index <= arr->length) {
    for (i = arr->length; i != index; i--) {
      arr->A[i] = arr->A[i - 1];
    }
    arr->A[i] = x;
    arr->length++;
    printf("Inserted %d at index %d\n", x, index);
    return;
  }
  printf("Not inserted.\n");
}

void delete (struct Array *arr, int index) {
  if (index >= 0 && index <= arr->length) {
    int i;
    for (i = index; i != arr->length - 1; i++) {
      arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
    printf("Deleted element at index %d\n", index);
    return;
  }
  printf("Not deleted.\n");
}

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int linearSearch(struct Array arr, int key) {
  int i, temp;
  for (i = 0; i < arr.length; i++) {
    if (key == arr.A[i]) {
      swap(&arr.A[i], &arr.A[i - 1]);
      return i;
    }
  }
  return -1;
}

void sort(struct Array *arr) {
  int i, j;
  for (i = 0; i < arr->length - 1; i++) {
    for (j = 0; j < arr->length - 1; j++) {
      if (arr->A[j] > arr->A[j + 1])
        swap(&arr->A[j], &arr->A[j + 1]);
    }
  }
}

int binarySearch(struct Array arr, int key) {
  int m, l = 0, h = arr.length - 1;
  while (l <= h) {
    m = (l + h) / 2;
    if (key == arr.A[m]) {
      return m;
    } else if (key > arr.A[m]) {
      l = m + 1;
    } else {
      h = m - 1;
    }
  }
  return -1;
}

int get(struct Array arr, int index) {
  if (index >= 0 && index < arr.length) {
    return arr.A[index];
  }
  return -1;
}

void set(struct Array *arr, int index, int x) {
  if (index >= 0 && index < arr->length) {
    arr->A[index] = x;
  }
}

int maxElement(struct Array arr) {
  int max = arr.A[0], i;
  for (i = 1; i < arr.length; i++) {
    if (arr.A[i] > max) {
      max = arr.A[i];
    }
  }
  return max;
}

int minElement(struct Array arr) {
  int min = arr.A[0], i;
  for (i = 1; i < arr.length; i++) {
    if (arr.A[i] < min) {
      min = arr.A[i];
    }
  }
  return min;
}

void reverse(struct Array *arr) {
  int i = 0, j = arr->length - 1, temp = 0;
  while (i < j) {
    swap(&arr->A[i], &arr->A[j]);
    i++;
    j--;
    printf("%d ", i);
  }
}

void insertIntoSorted(struct Array *arr, int x) {
  int i = arr->length - 1;
  if (arr->length != arr->size) {
    while (x < arr->A[i]) {
      arr->A[i + 1] = arr->A[i];
      i--;
    }

    arr->A[i + 1] = x;
    arr->length++;
    printf("Succesfully inserted  %d\n", x);
    return;
  }
  printf("Not inserted.\n");
}

void leftRotate(struct Array *arr) {
  int temp = arr->A[0], i;
  for (i = 0; i < arr->length - 1; i++) {
    arr->A[i] = arr->A[i + 1];
  }
  arr->A[i] = temp;
}

void isSorted(struct Array arr) {
  int i;
  for (i = 0; i <= arr.length - 2; i++) {
    if (arr.A[i] > arr.A[i + 1]) {
      printf("Array Not sorted .\n");
      return;
    }
  }
  printf("Array is sorted.\n");
}

void leftNegative(struct Array *arr) {
  int i = 0, j = arr->length - 1;

  while (i < j) {
    while (arr->A[i] < 0) //-ve
      i++;
    while (arr->A[j] >= 0) // +ve
      j--;
    if (i < j)
      swap(&arr->A[i], &arr->A[j]);
  }
}

void mergeArrays(struct Array arr1, struct Array arr2) {
  int i = 0, j = 0, k = 0;
  int totalLength = arr1.length + arr2.length;
  int arr3[10];
  printf("%d\n", totalLength);

  // both arrays should not terminate until that
  while (i < arr1.length && j < arr2.length) {
    if (arr1.A[i] < arr2.A[j]) {
      arr3[k++] = arr1.A[i++];
    } else {
      arr3[k++] = arr2.A[j++];
    }
  }

  // Copy remaning elements
  while (j < arr2.length)
    arr3[k++] = arr2.A[j++];

  while (i < arr1.length)
    arr3[k++] = arr1.A[i++];

  printf("Merged array\n");
  for (i = 0; i < totalLength; i++) {
    printf("%d ", arr3[i]);
  }
  printf("\n");
}

int main() {

  int i;

  //* Dynamic allocation

  //   struct Array arr;
  //   printf("Enter the size of the array: \n");
  //   scanf("%d", &arr.size);
  //   arr.length = 0;
  //   arr.A = (int *)malloc(sizeof(int) * arr.size);

  //   printf("Enter the Number of elements :\n");
  //   scanf("%d", &arr.length);

  //   // Enter the elements
  //   printf("Enter %d elements \n", arr.length);
  //   for (i = 0; i < arr.length; i++)
  //     scanf("%d", &arr.A[i]);

  // * Static allocation
  struct Array arr = {{-14, 56, 23, -48, 71}, 10, 5};
  struct Array arr1 = {{0, 1, 2, 3, 4}, 10, 5};

  // Initial Display
  display(arr);

  // Append
  append(&arr, 15);

  // Insert
  insert(&arr, 0, -43);

  // Delete
  delete (&arr, 3);

  // Linear Search
  printf("Index : %d\n", linearSearch(arr, 56));

  // Negative on left
  leftNegative(&arr);
  printf("After negative on left\n");
  display(arr);

  // Sort
  sort(&arr);

  // check if sorted
  isSorted(arr);
  display(arr);

  // Insert in an sorted array
  insertIntoSorted(&arr, 20);

  // binary Search
  printf("Index : %d\n", binarySearch(arr, 14));

  // Get
  int index = 3;
  printf("value at %d is %d\n", index, get(arr, index));

  // set
  set(&arr, index, 100);

  // Max
  printf("Max is : %d\n", maxElement(arr));

  // min
  printf("Min is : %d\n", minElement(arr));

  // reverse
  reverse(&arr);

  // Left rotate
  // leftRotate(&arr);

  // Merging
  sort(&arr);
  mergeArrays(arr, arr1);

  // display the elements
  display(arr);

  // Merge arrays

  return 0;
}