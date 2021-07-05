#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

const int mxN = 100;
const ull INF = 1e19;

int n, m, k, a, b;
ull c, x[mxN][mxN], y[mxN][mxN];

void combine(ull a[mxN][mxN], ull b[mxN][mxN]) {
  ull c[mxN][mxN];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) c[i][j] = INF;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        if (a[i][k] != INF && b[k][j] != INF)
          c[i][j] = min(c[i][j], a[i][k] + b[k][j]);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) a[i][j] = c[i][j];
}

int main() {
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) x[i][j] = y[i][j] = INF;
    y[i][i] = 0;
  }

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    x[a - 1][b - 1] = min(x[a - 1][b - 1], c);
  }

  while (k) {
    if (k & 1) combine(y, x);
    combine(x, x);
    k >>= 1;
  }

  if (y[0][n - 1] == INF)
    cout << "-1" << endl;
  else
    cout << y[0][n - 1] << endl;
}
