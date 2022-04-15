#include <bits/stdc++.h>

using namespace std;

int linearSearch(int arr[], int n, int key) {
  for (int i = 0; i < n; i++) {
    if (key == arr[i]) {
      return i;
    }
  }
  return -1;
}

int main() {

  int arr[] = {10, 20, 30, 40};
  int n = sizeof(arr) / sizeof(int);
  int key, index;
  cin >> key;

  index = linearSearch(arr, n, key);

  cout << key << (index == -1 ? " Not Found" : " Found") << endl;
}