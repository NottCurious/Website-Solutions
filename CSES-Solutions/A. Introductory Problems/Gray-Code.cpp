#include <bits/stdc++.h>
using namespace std;

const int mxN = 16;

int n;
bool b[mxN + 1];

void print() {
  for(int i = n; i > 0; i--)
    cout << b[i];
  cout << endl;
}

int main() {
  cin >> n;

  print();

  for(int i = 1; i < (1 << n); i++) {
    int LSB = __builtin_ffs(i);
    b[LSB] ^= 1;
    print();
  }
}
