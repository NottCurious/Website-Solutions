#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1000;

int n, q;
char c[mxN + 1][mxN + 1];
ll ds[mxN + 1][mxN + 1];

void update(int x, int y, ll val) {
  for (int i = x; i <= n; i += -i & i)
    for (int j = y; j <= n; j += -j & j) ds[i][j] += val;
}

ll query(int x, int y) {
  ll sum = 0;
  for (int i = x; i > 0; i -= -i & i)
    for (int j = y; j > 0; j -= -j & j) sum += ds[i][j];
  return sum;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> c[i][j];
      if (c[i][j] == '*') update(i, j, 1);
    }
  }
  for (int i = 0, t, x1, y1, x2, y2; i < q; i++) {
    cin >> t >> x1 >> y1;
    if (t == 1) {
      if (c[x1][y1] == '*') {
        update(x1, y1, -1);
        c[x1][y1] = '.';
      } else if (c[x1][y1] == '.') {
        update(x1, y1, 1);
        c[x1][y1] = '*';
      }
    } else if (t == 2) {
      cin >> x2 >> y2;
      cout << query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) +
                  query(x1 - 1, y1 - 1)
           << endl;
    }
  }
}
