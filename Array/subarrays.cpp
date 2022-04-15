#include <bits/stdc++.h>

using namespace std;

int main() {
  int arr[] = {10, 5, 2, 3, 6, 9, 11};
  int n = sizeof(arr) / sizeof(int);

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = i; k <= j; k++) {
        cout << arr[k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
}