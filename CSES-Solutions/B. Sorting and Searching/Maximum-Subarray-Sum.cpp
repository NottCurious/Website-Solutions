#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 2e5;

int n;
ll mxSum, curSum, x[mxN];

int main() {
  cin >> n;

  mxSum = LONG_MIN;
  for(int i = 0; i < n; i++) {
    cin >> x[i];
    mxSum = max(mxSum, x[i]);
  }

  for(int i = 0; i < n; i++) {
    curSum += x[i];
    mxSum = max(mxSum, curSum);
    if(curSum < 0) curSum = 0;
  }

  cout << mxSum;
}
