#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 1;

int n, x[mxN], ds[mxN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];

    int k = i - 1;

    while (x[k] >= x[i]) k = ds[k];
    ds[i] = k;
    printf("%d%c", ds[i], (" \n")[i == n]);
  }
}
