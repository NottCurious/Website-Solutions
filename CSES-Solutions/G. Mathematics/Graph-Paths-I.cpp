#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 100;
const ll mxMD = 1e9 + 7;

int n, m, k, a, b;
ll x[mxN][mxN], y[mxN][mxN];

void mult(ll a[mxN][mxN], ll b[mxN][mxN]) {
  ll c[n][n];
  memset(c, 0, sizeof(c));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= mxMD;
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) a[i][j] = c[i][j];
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    x[a - 1][b - 1]++;
  }
  for (int i = 0; i < n; i++) y[i][i] = 1;

  while (k) {
    if (k & 1) mult(y, x);
    mult(x, x);
    k >>= 1;
  }

  cout << y[0][n - 1];
}
