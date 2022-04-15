#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int n) {

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main() {
  int arr[] = {5, 4, 3, 2, 1};
  int n = (sizeof(arr)) / sizeof(int);

  bubbleSort(arr, n);

  for (int ele : arr) {
    cout << ele << " ";
  }
}