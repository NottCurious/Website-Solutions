#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e6 + 5;
const ll mxMD = 1e9 + 7;
const ll p1 = 31;
const ll p2 = 37;

int n, m, cnt;
ll sh1, sh2, th1, th2, pow1[mxN], pow2[mxN];
char S[mxN], T[mxN];

int main() {
  cin >> S >> T;
  n = strlen(S);
  m = strlen(T);

  if (m > n) {
    cout << "0\n";
    return 0;
  }

  pow1[0] = pow2[0] = 1;
  for (int i = 1; i < mxN; i++) {
    pow1[i] = (pow1[i - 1] * p1) % mxMD;
    pow2[i] = (pow2[i - 1] * p2) % mxMD;
  }

  for (int i = 0; i < m; i++) {
    sh1 = (sh1 + (S[i] - 'a' + 1) * pow1[m - i - 1]) % mxMD;
    sh2 = (sh2 + (S[i] - 'a' + 1) * pow2[m - i - 1]) % mxMD;
    th1 = (th1 + (T[i] - 'a' + 1) * pow1[m - i - 1]) % mxMD;
    th2 = (th2 + (T[i] - 'a' + 1) * pow2[m - i - 1]) % mxMD;
  }

  if (sh1 == th1 && sh2 == th2)
    cnt++;
  for (int i = m; i < n; i++) {
    sh1 = (sh1 * p1 - (S[i - m] - 'a' + 1) * pow1[m]) % mxMD;
    sh1 = (sh1 + (S[i] - 'a' + 1) + mxMD) % mxMD;
    sh2 = (sh2 * p2 - (S[i - m] - 'a' + 1) * pow2[m]) % mxMD;
    sh2 = (sh2 + (S[i] - 'a' + 1) + mxMD) % mxMD;
    if (sh1 == th1 && sh2 == th2)
      cnt++;
  }
  cout << cnt << endl;
}
