#include <bits/stdc++.h>
using namespace std;

const int mxX = 1e6;

int n, x, c, dp[mxX + 1];

int main() {
  cin >> n >> x;

  fill(dp + 1, dp + x + 1, INT_MAX);

  for (int i = 0; i < n; i++) {
    cin >> c;

    for (int j = 0; j <= x - c; j++)
      if (dp[j] != INT_MAX) dp[j + c] = min(dp[j + c], dp[j] + 1);
  }

  cout << (dp[x] == INT_MAX ? -1 : dp[x]);
}
