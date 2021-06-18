#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int mxN = 2e5 + 1;

int n, x, a;
pii p[mxN];

int find(int val) {
  int l = 1, r = n;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (p[m].first == val) {
      return p[m].second;
    } else if (p[m].first < val)
      l = m + 1;
    else
      r = m - 1;
  }

  return 0;
}

int main() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    p[i] = {a, i};
  }

  sort(p + 1, p + n + 1);

  for (int i = 1; i <= n; i++) {
    int other = find(x - p[i].first);

    if (other != 0 && other != p[i].second) {
      cout << p[i].second << " " << other << endl;
      return 0;
    }
  }

  cout << "IMPOSSIBLE";
}
