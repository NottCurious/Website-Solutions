#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxMD = 1e9 + 7;

ll n, x[6][6], y[6][6];

void init() {
  for (int i = 0; i < 6; i++) x[0][i] = 1;
  for (int i = 0; i < 5; i++) x[i + 1][i] = 1;
  for (int i = 0; i < 6; i++) y[i][i] = 1;
}

void mult(ll a[6][6], ll b[6][6]) {
  ll c[6][6];
  memset(c, 0, sizeof(c));
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      for (int k = 0; k < 6; k++) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= mxMD;
      }
    }
  }
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++) a[i][j] = c[i][j];
}

int main() {
  init();
  cin >> n;
  while (n) {
    if (n & 1) mult(y, x);
    mult(x, x);
    n >>= 1;
  }

  cout << y[0][0];
}
