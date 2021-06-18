#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
const int mxX = 1e5;

int n, x, h[mxN], s[mxN], dp[mxX + 1];

int main() {
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> h[i];
  for (int i = 0; i < n; i++) cin >> s[i];

  fill(dp + 1, dp + x + 1, -1);
  for (int i = 0; i < n; i++) {
    for (int j = x - h[i]; j >= 0; j--)
      if (dp[j] != -1) dp[j + h[i]] = max(dp[j + h[i]], dp[j] + s[i]);
  }

  for (int i = 1; i <= x; i++) dp[i] = max(dp[i], dp[i - 1]);
  cout << dp[x];
}
