#include <bits/stdc++.h>
using namespace std;

const int mxK = 101;
const int n = 8, sz = n * n;

int k;
double expected, ans[sz], dp[mxK][sz];

int main() {
  cin >> k;
  for (int i = 0; i < sz; i++) ans[i] = 1.0;

  for (int start = 0; start < sz; start++) {
    memset(dp, 0, sizeof(dp));
    dp[0][start] = 1.0;

    for (int i = 0; i < k; i++) {
      for (int u = 0; u < sz; u++) {
        vector<int> V;
        if (n <= u) V.push_back(u - n);
        if (u < n * (n - 1)) V.push_back(u + n);
        if (u % n != 0) V.push_back(u - 1);
        if (u % n != n - 1) V.push_back(u + 1);

        for (int v : V) dp[i + 1][v] += (dp[i][u] / V.size());
      }
    }

    for (int u = 0; u < sz; u++) ans[u] *= (1 - dp[k][u]);
  }

  for (int i = 0; i < sz; i++) expected += ans[i];

  printf("%.6f\n", expected);
}
