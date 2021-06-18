#include <iostream>
using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;

  ll pos = 0, len = 1, p10 = 1;

  while (pos < n) {
    pos += len * p10 * 9;
    len++;
    p10 *= 10;
  }

  len--;
  p10 /= 10;
  pos -= len * p10 * 9;
  ll push = (n - pos - 1) / len;
  string ans = to_string(p10 + push);
  ll id = n - (pos + push * len) - 1;
  cout << ans[id] << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
