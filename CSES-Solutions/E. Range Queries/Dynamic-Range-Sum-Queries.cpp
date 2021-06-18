#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5;

int n, q, t, a, b;
ll x[mxN + 1], ds[mxN + 1];

void update(int idx, ll val) {
  ll diff = val - x[idx];
  for (int i = idx; i <= n; i += -i & i) ds[i] += diff;
  x[idx] = val;
}

ll query(int idx) {
  ll sum = 0;
  for (int i = idx; i > 0; i -= -i & i) sum += ds[i];
  return sum;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> x[0];
    update(i, x[0]);
  }
  for (int i = 0; i < q; i++) {
    cin >> t >> a >> b;
    if (t == 1)
      update(a, b);
    else
      cout << query(b) - query(a - 1) << endl;
  }
}
