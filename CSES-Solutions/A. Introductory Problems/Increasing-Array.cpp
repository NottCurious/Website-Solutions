#include <iostream>
using namespace std;

#define ll long long
#define space " "
#define end1 "\n"

int main() {
  int n;
  ll x, mx, sum = 0;

  cin >> n >> mx;

  for (int i = 1; i < n; i++) {
    cin >> x;
    mx = max(mx, x);
    sum += (mx - x);
  }

  cout << sum;
}
