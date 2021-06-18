#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll t, mx, sum;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    mx = max(mx, t);
    sum += t;
  }

  cout << max(sum, 2 * mx);
}
