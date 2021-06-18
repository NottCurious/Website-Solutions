#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5 + 1;

int n, q, t, a, b, k;
ll x, ds[mxN];

void update(int idx, ll val) {
  for (int i = idx; i <= n; i += -i & i) ds[i] += val;
}

ll query(int idx) {
  ll sum = 0;
  for (int i = idx; i > 0; i -= -i & i) sum += ds[i];
  return sum;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    update(i, x);
    update(i + 1, -x);
  }
  for (int i = 0; i < q; i++) {
    cin >> t;
    if (t == 1) {
      cin >> a >> b >> x;
      update(b + 1, -x);
      update(a, x);
    } else if (t == 2) {
      cin >> k;
      cout << query(k) << endl;
    }
  }
}
