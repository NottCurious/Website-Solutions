#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxMD = 1e9 + 7;

int n, m;
ll ans;

ll fastpow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mxMD;
    a = (a * a) % mxMD;
    b >>= 1;
  }
  return res;
}

int main() {
  cin >> n >> m;
  for (int k = 0; k < n; k++) ans = (ans + fastpow(m, __gcd(k, n))) % mxMD;
  ans = (ans * fastpow(n, mxMD - 2)) % mxMD;
  cout << ans << endl;
}
