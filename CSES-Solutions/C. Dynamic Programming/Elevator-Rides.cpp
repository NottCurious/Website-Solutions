#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<int, int> pii;
const int mxN = 20;
const int INF = mxN + 1;

int n;
pii dp[1 << mxN];
ll x, w[mxN];

int main() {
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> w[i];

  dp[0] = {1, 0};
  for (int mask = 1; mask < (1 << n); mask++) {
    dp[mask] = {INF, 0};
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        pii can = dp[mask ^ (1 << i)];
        if (can.second + w[i] <= x) {
          can.second += w[i];
        } else {
          can.first++;
          can.second = w[i];
        }
        dp[mask] = min(dp[mask], can);
      }
    }
  }
  cout << dp[(1 << n) - 1].first;
}
