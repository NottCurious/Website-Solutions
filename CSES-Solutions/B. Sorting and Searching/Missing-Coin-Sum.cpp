#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 2e5;

int main() {
  int n, x[mxN];
  ll res;

  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> x[i];
  }

  sort(x, x + n);

  res = 1;

  for(int i = 0; i < n && x[i] <= res; i++) {
    res += x[i];
  }

  cout << res;
}
