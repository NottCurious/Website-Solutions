#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3 + 1;

char c;
int n, q, a[mxN][mxN];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> c;
      a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
      if (c == '*') a[i][j]++;
    }
  }
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1]
         << endl;
  }
}
