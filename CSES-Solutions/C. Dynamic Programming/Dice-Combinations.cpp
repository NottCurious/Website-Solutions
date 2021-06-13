#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
const int mxMD = 1e9 + 7;

int n, dp[mxN + 1];

int main() {
  cin >> n;

  dp[0] = 1;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= 6 && i - j >= 0; j++) {
      dp[i] = (dp[i] + dp[i - j]) % mxMD;
    }
  }

  cout << dp[n];
}
