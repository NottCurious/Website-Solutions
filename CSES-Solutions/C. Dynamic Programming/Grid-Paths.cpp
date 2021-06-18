#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1000;
const ll mxMD = 1e9 + 7;

int n;
char c[mxN + 1][mxN + 1];
ll dp[mxN + 1][mxN + 1];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> c[i][j];

  dp[1][1] = (c[1][1] == '.');
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (c[i][j] == '.') {
        if (c[i - 1][j] == '.') dp[i][j] += dp[i - 1][j];
        if (c[i][j - 1] == '.') dp[i][j] += dp[i][j - 1];
        dp[i][j] %= mxMD;
      }
    }
  }

  cout << dp[n][n];
}
