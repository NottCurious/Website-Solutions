#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 1;

int main() {
  int n, x, count, pos[mxN];
  cin >> n;

  for(int i = 1; i <= n; i++) {
    cin >> x;
    pos[x] = i;
  }

  count = 1;

  for(int i = 2; i <= n; i++) {
    if(pos[i - 1] > pos[i])
      count++;
  }

  cout << count;
}
