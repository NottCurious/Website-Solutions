#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, h, t;
  multiset<int> prices;

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> h;
    prices.insert(-h);
  }

  for (int i = 0; i < m; i++) {
    cin >> t;
    if (prices.lower_bound(-t) == prices.end())
      cout << "-1\n";
    else {
      cout << -(*prices.lower_bound(-t)) << endl;
      prices.erase(prices.lower_bound(-t));
    }
  }
}
