#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5, mxM = 2e5;

int compare(const void *a, const void *b) {
  int ia = *(int *) a;
  int ib = *(int *) b;

  return ia - ib;
}

int main() {
  int aa[mxN], bb[mxM];
  int n, m, k, i, j, count;

  cin >> n >> m >> k;

  for(i = 0; i < n; i++)
    cin >> aa[i];
  for(i = 0; i < m; i++)
    cin >> bb[i];

  qsort(aa, n, sizeof *aa, compare);
  qsort(bb, m, sizeof *bb, compare);
  count = 0;

  for(i = 0, j = 0; i < n && j < m; i++) {
    while(j < m && bb[j] < aa[i] - k)
      j++;

    if(j < m && bb[j] <= aa[i] + k) {
      j++;
      count++;
    }
  }

  cout << count;
}
