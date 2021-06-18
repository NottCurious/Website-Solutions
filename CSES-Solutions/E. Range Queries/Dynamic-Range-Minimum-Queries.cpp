#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;

int n, q, t, a, b, lo[4 * mxN], hi[4 * mxN], mn[4 * mxN];

void push(int i) {}

void pull(int i) { mn[i] = min(mn[2 * i], mn[2 * i + 1]); }

void init(int i, int l, int r) {
  lo[i] = l;
  hi[i] = r;
  if (l == r) {
    cin >> mn[i];
    return;
  }
  int m = l + (r - l) / 2;
  init(2 * i, l, m);
  init(2 * i + 1, m + 1, r);
  pull(i);
}

void assign(int i, int l, int r, int v) {
  if (l > hi[i] || r < lo[i]) return;
  if (l <= lo[i] && hi[i] <= r) {
    mn[i] = v;
    return;
  }

  push(i);
  assign(2 * i, l, r, v);
  assign(2 * i + 1, l, r, v);
  pull(i);
}

int minimum(int i, int l, int r) {
  if (l > hi[i] || r < lo[i]) return INT_MAX;
  if (l <= lo[i] && hi[i] <= r) return mn[i];

  push(i);
  int lmin = minimum(2 * i, l, r);
  int rmin = minimum(2 * i + 1, l, r);
  pull(i);

  return min(lmin, rmin);
}

int main() {
  cin >> n >> q;

  init(1, 1, n);

  for (int i = 0; i < q; i++) {
    cin >> t >> a >> b;
    if (t == 1)
      assign(1, a, a, b);
    else if (t == 2)
      cout << minimum(1, a, b) << endl;
  }
}
