#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;

int n, x, l, sum, cnt, a[mxN + 1];

int main() {
  cin >> n >> x;
  for (int r = 1; r <= n; r++) {
    cin >> a[r];
    sum += a[r];
    while (sum > x) sum -= a[l++];
    if (sum == x) cnt++;
  }
  cout << cnt;
}
