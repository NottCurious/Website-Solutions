#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 100;
const int mxX = 1e6;
const ll mxMD = 1e9 + 7;

int n, x, c[mxN];
ll dp[mxX + 1];

int main() {
  cin >> n >> x;

  for (int i = 0; i < n; i++) cin >> c[i];

  dp[0] = 1;
  for (int i = 0; i < x; i++)
    if (dp[i] != 0)
      for (int j = 0; j < n; j++)
        if (i + c[j] <= x) dp[i + c[j]] = (dp[i + c[j]] + dp[i]) % mxMD;

  cout << dp[x];
}
