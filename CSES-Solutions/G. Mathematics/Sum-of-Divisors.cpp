#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxMD = 1e9 + 7;

ll n, sum;

ll sigma(ll x) { return ((x % mxMD) * ((x + 1) % mxMD) / 2) % mxMD; }

int main() {
  cin >> n;
  for (ll l = 1; l <= n; l++) {
    ll r = n / (n / l);
    sum += (n / l) % mxMD * (sigma(r) - sigma(l - 1) + mxMD) % mxMD;
    sum = (sum + mxMD) % mxMD;
    l = r;
  }
  cout << sum << endl;
}
