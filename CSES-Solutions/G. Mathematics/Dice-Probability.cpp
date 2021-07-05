#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e2;

int n, a, b;
double sum, dp[mxN + 1][6 * mxN + 1];

int main() {
  cin >> n >> a >> b;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 6 * mxN; j++)
      for (int k = 1; k <= 6; k++)
        if (j - k >= 0) dp[i][j] += dp[i - 1][j - k] / 6;
  for (int i = a; i <= b; i++) sum += dp[n][i];
  printf("%.6f\n", sum);
}
