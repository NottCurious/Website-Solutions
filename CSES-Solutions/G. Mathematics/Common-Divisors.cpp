#include <bits/stdc++.h>
using namespace std;

const int mxX = 1e6;

int n, a, cnt, d[mxX + 1];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    d[a]++;
  }
  for (int i = mxX; i >= 1; i--) {
    cnt = 0;
    for (int j = i; j <= mxX; j += i) cnt += d[j];
    if (cnt >= 2) {
      cout << i << endl;
      return 0;
    }
  }
}
