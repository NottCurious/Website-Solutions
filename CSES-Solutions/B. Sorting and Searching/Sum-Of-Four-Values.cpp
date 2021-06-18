#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define space " "

typedef pair<int, int> pii;
const int mxN = 1e3 + 1;

int n;
ll x, a[mxN];
unordered_map<ll, vector<pii>> mp;

int main() {
  cin >> n >> x;

  mp.reserve(mxN * mxN);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 1; j < i; j++) {
      ll psum = a[i] + a[j];
      if (psum >= x) continue;
      if (mp.find(x - psum) != mp.end()) {
        for (pii P : mp[x - psum]) {
          if (P.first != j && P.second != j && P.first != i && P.second != i) {
            cout << P.first << space << P.second << space << j << space << i;
            return 0;
          }
        }
      } else
        mp[psum].push_back({j, i});
    }
  }
  cout << "IMPOSSIBLE";
}
