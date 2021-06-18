#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;

int main() {
  int n, x, l, ans = 0, p[mxN];

  cin >> n >> x;

  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  sort(p, p + n);

  l = 0;

  for (int i = n - 1; i >= l; i--) {
    if (p[l] + p[i] <= x) {
      l++;
    }
    ans++;
  }

  cout << ans;
}
