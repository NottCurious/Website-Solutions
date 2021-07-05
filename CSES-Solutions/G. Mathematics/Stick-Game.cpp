#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
const int mxK = 100;

int n, k, p[mxK];
bool dp[mxN + 1];

int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) cin >> p[i];

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < k; j++)
      if (i - p[j] >= 0 && !dp[i - p[j]]) dp[i] = true;
    printf("%c", ("LW")[dp[i]]);
  }
}
