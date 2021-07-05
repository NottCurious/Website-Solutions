#include <bits/stdc++.h>
using namespace std;

int t, n, p, num;

int main() {
  cin >> t;
  for (int j = 0; j < t; j++) {
    cin >> n;
    num = 0;
    for (int i = 0; i < n; i++) {
      cin >> p;
      if (i % 2) num ^= p;
    }
    cout << (num ? "first\n" : "second\n");
  }
}
