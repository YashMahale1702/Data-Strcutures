#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int n) {
  int current, prev, i, j;
  for (i = 1; i < n; i++) {
    current = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > current) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = current;
  }
}

int main() {
  int arr[] = {5, 4, 3, 2, 1};
  int n = (sizeof(arr)) / sizeof(int);

  insertionSort(arr, n);

  for (int ele : arr) {
    cout << ele << " ";
  }
}