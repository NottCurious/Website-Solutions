#include <bits/stdc++.h>
using namespace std;

#define ll long long

const double EPS = 0.001;
const int mxK = 20;

int k;
ll n, cnt, a[mxK];

int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) cin >> a[i];

  cnt = n;
  double RHS = log(n) + EPS;
  for (int mask = 0; mask < (1 << k); mask++) {
    bool odd = (__builtin_popcount(mask) & 1);

    ll prod = 1;
    double LHS = 0.0;
    for (int i = 0; i < k; i++) {
      if (mask & (1 << i)) {
        LHS += log(a[i]);
        prod *= a[i];
      }
    }

    if (LHS < RHS) cnt += (odd ? 1 : -1) * (n / prod);
  }

  cout << cnt;
}
