#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxM = (int)(500 * 501 / 4);
const int mxMD = 1e9 + 7;
static int dp[1 + mxM];

int main() {
  int n, m, i, j;

  cin >> n;
  if (n % 4 == 1 || n % 4 == 2) {
    cout << "0";
    return 0;
  }

  m = n * (n + 1) / 4;
  dp[0] = 1;

  for (i = 1; i <= n; i++)
    for (j = m; j >= i; j--) dp[j] = (dp[j] + dp[j - i]) % mxMD;

  cout << (ll)dp[m] * (mxMD + 1) / 2 % mxMD;
}
