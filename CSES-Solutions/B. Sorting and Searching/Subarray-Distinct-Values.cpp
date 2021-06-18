#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5 + 5;

int n, k, x[mxN];
map<int, int> freq;
ll ans;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> x[i];

  int unique = 0;
  int r = 0;
  for (int l = 1; l <= n; l++) {
    while (r < n && (freq[x[r + 1]] >= 1 || unique < k)) {
      r++;
      freq[x[r]]++;
      if (freq[x[r]] == 1) unique++;
    }

    ans += (r - l + 1);

    freq[x[l]]--;
    if (!freq[x[l]]) unique--;
  }

  cout << ans;
}
