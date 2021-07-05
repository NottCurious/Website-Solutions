#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e2 + 1;

int n, r[mxN];
double ans;

int f(int x) { return x * (x - 1) / 2; }

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> r[i];
    for (int j = 0; j < i; j++) {
      int tot = (r[j] <= r[i]) ? f(r[j]) : (f(r[i]) + (r[j] - r[i]) * r[i]);
      ans += (double)tot / (r[i] * r[j]);
    }
  }
  printf("%.6f\n", ans);
}
