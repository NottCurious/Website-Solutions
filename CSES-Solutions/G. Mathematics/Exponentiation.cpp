#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxMD = 1e9 + 7;

int n;
ll a, b;

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
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    cout << fastpow(a, b) << endl;
  }
}
