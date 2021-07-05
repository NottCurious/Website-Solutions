#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mxMD = 1e9 + 7;

ll n, a, b, c;

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
  cin >> n;
  a = n * n;
  b = (a + 3 * (n & 1)) / 4;
  c = (a + (n & 1)) / 2;
  cout << ((fastpow(2, a) + 2 * fastpow(2, b) + fastpow(2, c)) *
           fastpow(4, mxMD - 2)) %
              mxMD
       << endl;
}
