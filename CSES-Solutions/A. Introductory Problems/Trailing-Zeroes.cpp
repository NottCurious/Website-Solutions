#include <iostream>
using namespace std;

int main() {
  int n, ans;
  cin >> n;

  while (n > 0) {
    n /= 5;
    ans += n;
  }

  cout << ans;
}
