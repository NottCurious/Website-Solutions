#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e3 + 5;

int n, m, dp[mxN][mxN];
char a[mxN], b[mxN];

int main() {
  cin >> a >> b;
  n = strlen(a);
  m = strlen(b);

  memset(dp, 0x3f, sizeof(dp));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0)
        dp[i][j] = j;
      else if (j == 0)
        dp[i][j] = i;
      else if (a[i - 1] == b[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
    }
  }

  cout << dp[n][m];
}
