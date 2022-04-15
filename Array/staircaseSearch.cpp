#include <bits/stdc++.h>

using namespace std;

pair<int, int> stairCaseSearch(int arr[4][4], int n, int m, int key) {
  int i = 0, j = m - 1;

  // if not found
  if (key < arr[0][0] or key > arr[n - 1][m - 1]) {
    return {-1, -1};
  }

  while (i <= n - 1 and j >= 0) {
    if (key == arr[i][j])
      return {i, j};
    else if (key < arr[i][j])
      j--;
    else if (key > arr[i][j])
      i++;
  }

  return {-1, -1};
}

int main() {
  int n = 4, m = 4, key;
  pair<int, int> coordinate;
  int arr[4][4] = {
      {10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50},
  };

  cin >> key;

  coordinate = stairCaseSearch(arr, n, m, key);

  cout << coordinate.first << " " << coordinate.second << endl;
  return 0;
}