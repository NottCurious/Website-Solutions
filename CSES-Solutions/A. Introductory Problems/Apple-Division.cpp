#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int n, p[20];
  ll a, b, best;

  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }

  best = LONG_MAX;

  for(int i = 0; i < (1 << n); i++) {
    a = 0; b = 0;

    for(int j = 0; j < n; j++) {
      if(i & (1 << j)) a += p[j];
      else b += p[j];
    }

    best = min(best, abs(a - b));
  }

  cout << best;
}
