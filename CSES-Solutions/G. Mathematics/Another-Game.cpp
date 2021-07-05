#include <bits/stdc++.h>
using namespace std;

int t, n, x;
bool even;

int main() {
  cin >> t;
  for (int j = 0; j < t; j++) {
    cin >> n;
    even = true;
    for (int i = 0; i < n; i++) {
      cin >> x;
      even &= !(x & 1);
    }
    cout << (even ? "second" : "first") << endl;
  }
}
