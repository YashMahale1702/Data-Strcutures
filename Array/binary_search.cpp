#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int n, int key) {
  int l = 0, h = n - 1, mid, count = 0;

  while (l <= h) {
    count++;
    mid = (l + h) / 2;
    if (key == arr[mid]) {
      cout << count << endl;
      return mid;
    } else if (key > arr[mid]) {
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }

  return -1;
}

int main() {

  int arr[] = {10, 20, 30, 40, 50};
  int n = sizeof(arr) / sizeof(int);
  int key, index;
  cin >> key;

  //
  index = binarySearch(arr, n, key);
  cout << key << (index == -1 ? " Not Found" : " Found") << endl;
  return 0;
}