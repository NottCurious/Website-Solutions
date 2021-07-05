#include <bits/stdc++.h>
using namespace std;

int n, k;
double ans, a, b;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    a = b = 1.0;
    for (int j = 1; j <= n; j++) {
      a *= (double)i / k;
      b *= (double)(i - 1) / k;
    }
    ans += (a - b) * i;
  }
  printf("%.6f\n", ans);
}
