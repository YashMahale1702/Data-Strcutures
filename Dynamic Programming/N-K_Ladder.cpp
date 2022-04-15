#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, k, sum;
  cin >> n >> k;

  vector<int> dp(n + 1, 0);
  dp[0] = dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    sum = 0;
    for (int j = i - 1; j >= 0 && j >= i - k; j--) {
      sum += dp[j];
    }
    dp[i] = sum;
  }

  cout << dp[n] << endl;
}