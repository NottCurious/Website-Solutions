#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e6;
const ll mxMD = 1e9 + 7;

int n;
ll dp[mxN + 1];

void init() {
  dp[2] = 1;
  for (int i = 3; i <= mxN; i++)
    dp[i] = (i - 1) * (dp[i - 2] + dp[i - 1]) % mxMD;
}

int main() {
  init();
  cin >> n;
  cout << dp[n];
}
