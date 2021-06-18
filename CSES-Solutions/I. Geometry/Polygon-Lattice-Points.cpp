#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5 + 5;

int n;
ll area, boundary, inside, x[mxN], y[mxN];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  x[n] = x[0];
  y[n] = y[0];

  for (int i = 0; i < n; i++) {
    area += x[i] * y[i + 1];
    area -= y[i] * x[i + 1];
  }
  area = abs(area);

  for (int i = 0; i < n; i++) {
    if (x[i + 1] == x[i])
      boundary += abs(y[i + 1] - y[i]);
    else if (y[i + 1] == y[i])
      boundary += abs(x[i + 1] - x[i]);
    else
      boundary += __gcd(abs(x[i + 1] - x[i]), abs(y[i + 1] - y[i]));
  }

  cout << (area + 2 - boundary) / 2 << " " << boundary;
}
