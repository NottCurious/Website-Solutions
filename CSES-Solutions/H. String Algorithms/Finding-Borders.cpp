#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxMD = 1e9 + 7;
const ll p1 = 31;
const ll p2 = 37;
const int mxN = 1e6 + 5;

int n;
ll pow1[mxN], pow2[mxN], ph1, ph2, sh1, sh2;
char S[mxN];

int main() {
  cin >> S;
  n = strlen(S);

  pow1[0] = pow2[0] = 1;
  for (int i = 1; i < n; i++) {
    pow1[i] = (pow1[i - 1] * p1) % mxMD;
    pow2[i] = (pow2[i - 1] * p2) % mxMD;
  }

  for (int i = 0; i < n - 1; i++) {
    int l = (S[i] - 'a' + 1);
    int r = (S[n - i - 1] - 'a' + 1);

    ph1 = (ph1 + l * pow1[i]) % mxMD;
    ph2 = (ph2 + l * pow2[i]) % mxMD;
    sh1 = (sh1 * p1 + r) % mxMD;
    sh2 = (sh2 * p2 + r) % mxMD;

    if (ph1 == sh1 && ph2 == sh2)
      cout << i + 1 << " ";
  }
}
