#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void reverse(int arr[], int n) {
  int i = 0, j = n - 1;
  while (i <= j) {
    swap(&arr[i], &arr[j]);
    i++;
    j--;
  }
  cout << i << endl;
}

void display(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

int main() {

  int arr[] = {10, 20, 30, 40};
  int n = sizeof(arr) / sizeof(int);
  int key, index;

  reverse(arr, n);
  display(arr, n);
}