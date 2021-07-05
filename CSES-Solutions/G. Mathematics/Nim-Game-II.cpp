#include <bits/stdc++.h>
using namespace std;

int t, n, x, num;

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    num = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      num ^= (x % 4);
    }
    cout << (num ? "first\n" : "second\n");
  }
}
