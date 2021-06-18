#include <iostream>
using namespace std;

#define ll long long
#define space " "
#define end1 "\n"

int main() {
  ll n;
  cin >> n;
  ll sum = 0;

  for (int i = 0; i < n - 1; i++) {
    ll a = 0;
    cin >> a;
    sum += a;
  }

  cout << ((n * (n + 1)) / 2) - sum;
}
