#include <stdio.h>
#include <stdlib.h>

void singleMissing(int A[], int n) {
  int i = 0, diff = A[0] - 0, curDiff = 0;

  for (; i < n; i++) {
    curDiff = A[i] - i;
    if (curDiff != diff) {
      printf("single missing elements is %d\n", i + diff);
      return;
    }
  }
}

void multipleMissing(int A[], int n) {
  int i = 0, curDiff, diff = A[0] - 0;
  for (; i < n; i++) {
    curDiff = A[i] - i;
    if (curDiff != diff) {
      while (curDiff != diff) {
        printf("Missing Element is %d \n", i + diff);
        diff++;
      }
    }
  }
}

void duplicates(int A[], int n) {
  int i, prev = 0;
  for (i = 0; i < n - 1; i++) {
    if (A[i] == A[i + 1] && A[i] != prev) {
      prev = A[i];
      printf("Duplicate element is %d\n", A[i]);
    }
  }
}

void duplicateWithCount(int A[], int n) {
  int i, j = 0, count;
  for (i = 0; i < n - 1; i++) {
    if (A[i] == A[i + 1]) {
      j = i;
      count = 0;
      while (A[j] == A[i]) {
        count++;
        j++;
      }

      printf("Duplicate element is %d and is %d times\n", A[i], count);
      i = j;
    }
  }
}

void duplicateUnsortedArray(int A[], int n) {
  int i, j, count = 0;
  for (i = 0; i < n - 1; i++) {

    // If it is not already counted
    if (A[i] != -1) {
      count = 1;
      for (j = i + 1; j < n; j++) {
        if (A[i] == A[j]) {
          count++;
          A[j] = -1;
        }
      }

      //
      if (count > 1)
        printf("Found Duplicate %d for %d times\n", A[i], count);
    }
  }
}

void minMax(int A[], int n) {
  int i, min = A[0], max = A[0];
  for (i = 1; i < n; i++) {
    if (A[i] < min) {
      min = A[i];
      continue;
    } else if (A[i] >= max) {
      max = A[i];
    }
  }
  printf("Min %d  Max %d\n", min, max);
}

int main() {
  int A[] = {1, 8, 3, 6, 4, 5, 12, 1, 3, 6, 8, 5, 1}, n;
  n = sizeof(A) / sizeof(A[0]);

  // *Find single missing element
  // singleMissing(A, n);

  // *Find multiple missing element
  // multipleMissing(A, n);

  //* Duplicates
  // duplicates(A, n);

  //* Duplicates with count
  // duplicateWithCount(A, n);

  //* Duplicates for unsorted array with count
  // duplicateUnsortedArray(A, n);

  //* Min and Max
  minMax(A, n);

  return 0;
}