#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e6;
const ll mxMD = 1e9 + 7;

int n, m;
ll fact[mxN], inv[mxN];

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
  for (int i = 1; i < mxN; i++) {
    fact[i] = i * fact[i - 1] % mxMD;
    inv[i] = inverse(fact[i]);
  }
}

ll choose(int n, int k) { return fact[n] * inv[k] % mxMD * inv[n - k] % mxMD; }

int main() {
  init();
  scanf("%d %d", &n, &m);
  printf("%lld\n", choose(n + m - 1, m));
}
