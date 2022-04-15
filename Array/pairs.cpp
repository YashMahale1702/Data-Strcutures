#include <bits/stdc++.h>

using namespace std;

int main() {
  int arr[] = {10, 5, 2, 3, -6, 9, 11};
  int n = sizeof(arr) / sizeof(int);

  cout << "Possible pairs are : \n";

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cout << arr[i] << ", " << arr[j] << endl;
    }
    cout << endl;
  }
  return 0;
}