#include <iostream>
using namespace std;
const int mxN = 1e6;

int main() {
  static int dd[mxN + 1];
  int a, b, t;

  for (a = 1; a <= mxN; a++)
    for (b = a; b <= mxN; b += a) dd[b]++;
  cin >> t;
  while (t--) {
    int n;

    cin >> n;
    cout << dd[n] << endl;
  }
}
