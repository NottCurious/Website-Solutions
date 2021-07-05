#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e6 + 5;
const ll mxMD = 1e9 + 7;

int n, freq[26];
char S[mxN];
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

int main() {
  cin >> S;
  n = strlen(S);
  init();

  for (int i = 0; i < n; i++) freq[(int)(S[i] - 'a')]++;

  ll ans = fact[n];
  for (int i = 0; i < 26; i++) ans = ans * inv[freq[i]] % mxMD;
  cout << ans << endl;
}
