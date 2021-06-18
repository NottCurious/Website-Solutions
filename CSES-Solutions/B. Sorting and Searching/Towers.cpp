#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  multiset<int> s;
  multiset<int>::iterator it;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> k;

    it = s.upper_bound(k);
    if (it != s.end()) s.erase(it);

    s.insert(k);
  }

  cout << (int)s.size();
}
