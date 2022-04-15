#include <bits/stdc++.h>

using namespace std;
vector<int> dp(1000, -1);

int fib(int n) {

  // already exists
  if (dp[n] != -1) {
    return dp[n];
  }

  //
  dp[n] = fib(n - 1) + fib(n - 2);
  return dp[n];
}

int main() {
  int n;
  cin >> n;
  dp[0] = 0;
  dp[1] = 1;

  cout << fib(n);
}