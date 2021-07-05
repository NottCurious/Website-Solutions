#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxA = 1e6;
const ll mxMD = 1e9 + 7;

int n, a, b;
ll fact[mxA + 1], inv[mxA + 1];

ll inverse(ll x) {
  ll res = 1;
  ll expo = mxMD - 2;
  while (expo > 0) {
    if (expo & 1) res = (res * x) % mxMD;
    x = (x * x) % mxMD;
    expo >>= 1;
  }
  return res;
}

void init() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i <= mxA; i++) {
    fact[i] = i * fact[i - 1] % mxMD;
    inv[i] = inverse(fact[i]);
  }
}

int main() {
  init();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    cout << fact[a] * inv[b] % mxMD * inv[a - b] % mxMD << endl;
  }
}
