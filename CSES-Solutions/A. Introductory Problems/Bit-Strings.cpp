#include <iostream>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

ll fastpow(int x) {
  ll res = 1;
  ll a = 2;

  while(x > 0) {
    if(x & 1) {
      res = (res * a) % MOD;
    }

    a = (a * a) % MOD;
    x >>= 1;
  }

  return res;
}

int main() {
  ll n;
  cin >> n;

  cout << fastpow(n);
}
