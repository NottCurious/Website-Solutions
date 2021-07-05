#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxMD = 1e9 + 7;

ll n, num, denom;

ll fastpow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mxMD;
    a = (a * a) % mxMD;
    b >>= 1;
  }
  return res;
}

ll inverse(ll a) { return fastpow(a, mxMD - 2); }

int main() {
  cin >> n;
  if (n & 1)
    cout << "0" << endl;
  else {
    num = 1;
    for (int i = 1; i <= n; i++) num = (num * i) % mxMD;

    denom = 1;
    for (int i = 1; i <= n / 2; i++) denom = (denom * i) % mxMD;
    denom = (denom * denom) % mxMD;
    denom = (denom * (n / 2 + 1)) % mxMD;

    cout << (num * inverse(denom)) % mxMD << endl;
  }
}
