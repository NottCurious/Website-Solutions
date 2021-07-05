#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 1;

/**
 * A036685
 * Retrieved from https://oeis.org/A036685
 */

int t, lose[42] = {0,   1,   2,   4,   7,   10,  20,  23,  26,  50,  53,
                   270, 273, 276, 282, 285, 288, 316, 334, 337, 340, 346,
                   359, 362, 365, 386, 389, 392, 566, 630, 633, 636, 639,
                   673, 676, 682, 685, 923, 926, 929, 932, 1222};
bool b[mxN];

void init() {
  for (int x : lose) b[x] = true;
}

int main() {
  init();
  cin >> t;
  for (int i = 0, n; i < t; i++) {
    cin >> n;
    cout << (b[n] ? "second" : "first") << endl;
  }
}
