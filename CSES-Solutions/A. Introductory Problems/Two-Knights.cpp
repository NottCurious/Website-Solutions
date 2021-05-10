#include <iostream>
using namespace std;

#define ll long long

int main() {
  int n;
  cin >> n;

  for(int i = 1; i <= n; i++) {
    ll count = 1LL + (i - 1) * (i - 2) / 2;
    count = count * (i - 1) * (i + 4);
    cout << count << endl;
  }
}
