#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5;

int n, p[mxN];
ll median, sum;

int main() {
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }

  sort(p, p + n);

  median = p[(n - 1) / 2];

  for(int i = 0; i < n; i++) {
    sum += abs(p[i] - median);
  }

  cout << sum;
}
