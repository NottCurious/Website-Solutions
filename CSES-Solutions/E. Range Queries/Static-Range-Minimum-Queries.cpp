#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 1;
const int logN = ceil(log2(mxN)) + 1;

int n, q, a, b, l, k, x[mxN][logN];

int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> x[i][0];

  for (int i = 1; i < logN; i++)
    for (int j = 0; j <= n - (1 << i); j++)
      x[j][i] = min(x[j][i - 1], x[j + (1 << (i - 1))][i - 1]);

  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    a--;
    b--;
    l = b - a + 1;
    k = log2(l);
    cout << min(x[a][k], x[b - (1 << k) + 1][k]) << endl;
  }
}
