#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxMD = 1e9 + 7;

ll n, x[2][2], y[2][2];

void mult(ll a[2][2], ll b[2][2]) {
  ll c[2][2];
  memset(c, 0, sizeof(c));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= mxMD;
      }
    }
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) a[i][j] = c[i][j];
}

int main() {
  x[0][1] = x[1][0] = x[1][1] = y[0][0] = y[1][1] = 1;

  cin >> n;
  while (n) {
    if (n & 1) mult(y, x);
    mult(x, x);
    n >>= 1;
  }

  cout << y[0][1] << endl;
}
