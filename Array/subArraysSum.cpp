#include <bits/stdc++.h>

using namespace std;

// brute force approach n^3
int largetSubArraySum1(int arr[], int n) {

  int largestSum = INT_MIN;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int currSum = 0;
      for (int k = i; k <= j; k++) {
        currSum += arr[k];
      }

      // compare the currentSum'
      largestSum = max(largestSum, currSum);
    }
  }

  return largestSum;
}

// Prefix sum approach n^2
int largetSubArraySum2(int arr[], int n) {
  int prefixArr[n], largestSum = 0;

  // prefix array -> Cumsum array
  prefixArr[0] = arr[0];
  for (int i = 1; i < n; i++) {
    prefixArr[i] = prefixArr[i - 1] + arr[i];
  }

  //
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int currSum = i >= 1 ? prefixArr[j] - prefixArr[i - 1] : prefixArr[j];

      // compare the currentSum'
      largestSum = max(largestSum, currSum);
    }
  }
  return largestSum;
}

// Kadanes Alogorithm
int largetSubArraySum3(int arr[], int n) {

  int largestSum = INT_MIN, start = 0, end = 0, startTemp = 0;
  int currSum = 0;
  for (int i = 0; i < n; i++) {
    currSum += arr[i];

    //-ve no then start over
    if (currSum < 0) {
      currSum = 0;
      startTemp = i + 1;
    }
    if (currSum > largestSum) {
      largestSum = currSum;
      end = i;
      start = startTemp;
    }
  }
  cout << start << " " << end;
  return largestSum;
}

int main() {
  int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
  int n = sizeof(arr) / sizeof(int);

  cout << "Brute Force sum : " << largetSubArraySum1(arr, n) << endl;
  cout << "Prefix array sum : " << largetSubArraySum2(arr, n) << endl;
  cout << "Kadanes Algo sum : " << largetSubArraySum3(arr, n) << endl;
}