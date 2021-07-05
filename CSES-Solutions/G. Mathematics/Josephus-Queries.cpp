#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int q;
map<pii, int> f;

int solve(int n, int k) {
  if (f[{n, k}]) return f[{n, k}];

  if (n == 1) return f[{n, k}] = 1;
  if (2 * k <= n) return f[{n, k}] = 2 * k;

  int newN = (n / 2) + (n & 1);
  int newK = k - n / 2;

  if (n & 1) {
    int ans = solve(newN, newK);
    return f[{n, k}] = ((2 * ans - 3) + (n + 1)) % (n + 1);
  } else {
    return f[{n, k}] = 2 * solve(newN, newK) - 1;
  }
}

int main() {
  cin >> q;
  for (int i = 0, n, k; i < q; i++) {
    cin >> n >> k;
    cout << solve(n, k) << endl;
  }
}
