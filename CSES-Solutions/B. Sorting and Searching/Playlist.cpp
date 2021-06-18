#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, l, ans = 0;
  map<int, int> mp;

  cin >> n;

  l = 1;

  for (int i = 1; i <= n; i++) {
    cin >> k;

    if (mp[k]) {
      ans = max(ans, i - l);
      l = max(l, mp[k] + 1);
      mp[k] = i;
    } else {
      ans = max(ans, i - l + 1);
      mp[k] = i;
    }
  }

  ans = max(n - l + 1, ans);
  cout << ans;
}
