#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5;
const ll mxMD = 1e9 + 7;

int n;
ll x[mxN], k[mxN];
ll tau, sigma, pi, mu;

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
  for (int i = 0; i < n; i++) cin >> x[i] >> k[i];

  tau = 1;
  for (int i = 0; i < n; i++) tau = (tau * (k[i] + 1)) % mxMD;

  sigma = 1;
  for (int i = 0; i < n; i++) {
    ll numerator = (fastpow(x[i], k[i] + 1) - 1 + mxMD) % mxMD;
    ll denominator = fastpow(x[i] - 1, mxMD - 2);
    ll geoSum = numerator * denominator % mxMD;
    sigma = (sigma * geoSum) % mxMD;
  }

  pi = 1;
  mu = 1;
  for (int i = 0; i < n; i++) {
    ll p = fastpow(x[i], k[i] * (k[i] + 1) / 2);
    mu = fastpow(mu, k[i] + 1) * fastpow(p, pi) % mxMD;
    pi = (pi * (k[i] + 1)) % (mxMD - 1);
  }

  cout << tau << " " << sigma << " " << mu << endl;
}
