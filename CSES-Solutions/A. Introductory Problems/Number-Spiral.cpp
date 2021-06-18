#include <iostream>
using namespace std;

#define ll long long

ll solve(ll x, ll y) {
  ll l = max(x, y) - 1;

  if (l & 1) {
    if (x < y)
      return l * l + x;
    else
      return l * l + 2 * l - y + 2;
  } else {
    if (x < y)
      return l * l + 2 * l - x + 2;
    else
      return l * l + y;
  }
}

int main() {
  int t;
  ll x, y;

  cin >> t;
  while (t--) {
    cin >> x >> y;

    cout << solve(x, y) << endl;
  }
}
