#include <bits/stdc++.h>
using namespace std;

int n, a;
multiset<int> S;
multiset<int>::iterator it;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    S.insert(a);
    it = S.lower_bound(a);
    it++;
    if (it != S.end()) S.erase(it);
  }
  cout << (int)S.size();
}
