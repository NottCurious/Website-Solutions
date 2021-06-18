#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;

int n, dp[mxN + 1];

int main() {
  cin >> n;
  fill(dp + 1, dp + n + 1, INT_MAX);

  for (int i = 1; i <= n; i++) {
    int d = i;
    while (d > 0) {
      if (d % 10 != 0) dp[i] = min(dp[i], dp[i - (d % 10)] + 1);
      d /= 10;
    }
  }
  cout << dp[n];
}
