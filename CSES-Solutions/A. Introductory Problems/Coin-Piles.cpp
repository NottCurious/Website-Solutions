#include <iostream>
using namespace std;

int main() {
  int t, a, b;

  cin >> t;

  while(t--) {
    cin >> a >> b;

    cout << (((a + b) % 3 != 0 || a > 2 * b || b > 2 * a)? "NO\n" : "YES\n");
  }
}
