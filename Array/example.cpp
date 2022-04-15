#include <bits/stdc++.h>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  long int n;
  long int largestSum = INT_MIN, start = 0, end = 0, startTemp = 0;
  long int currSum = 0;
  cin >> n;

  long int arr[n];

  for (long int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // first scan
  for (long int i = 0; i < n; i++) {
    currSum += arr[i];

    //-ve no then start over
    if (currSum < 0) {
      currSum = 0;
      startTemp = i + 1;
    }

    // if largest then swap and change indices
    if (currSum > largestSum) {
      largestSum = currSum;
      end = i;
      start = startTemp;
    }
  }

  if (end != -1)
    cout << largestSum << endl;
  else {
    // when all elements are negative in the array
    largestSum = arr[0];
    start = end = 0;

    // maximum element in array
    for (int i = 1; i < n; i++) {
      if (arr[i] > largestSum) {
        largestSum = arr[i];
        start = end = i;
      }
    }
    cout << largestSum << endl;
  }

  cout << largestSum << endl;
  largestSum = INT_MIN;
  currSum = 0;

  // second scan
  for (long int i = 0; i < n; i++) {
    if (i < start || i > end) {
      currSum += arr[i];

      if (currSum < 0) {
        currSum = 0;
      }

      if (currSum > largestSum) {
        largestSum = currSum;
      }
    }
  }

  cout << largestSum << endl;

  return 0;
}