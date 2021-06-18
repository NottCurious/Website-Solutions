#include <iostream>
using namespace std;

void move(int from, int to, int depth) {
  if (depth == 1) {
    cout << from << " " << to << endl;
    return;
  }

  int other = 6 - from - to;

  move(from, other, depth - 1);
  cout << from << " " << to << endl;
  move(other, to, depth - 1);
}

int main() {
  int n;
  cin >> n;

  cout << (1 << n) - 1 << endl;
  move(1, 3, n);
}
