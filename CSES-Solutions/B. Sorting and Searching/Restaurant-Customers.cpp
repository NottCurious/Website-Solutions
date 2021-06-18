#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

const int mxN = 2e5;

void init_rand() {
  struct timeval tv;

  gettimeofday(&tv, NULL);
  srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) { return (rand() * 45677LL + rand()) % n; }

int compare(const void *a, const void *b) {
  int ia = *(int *)a;
  int ib = *(int *)b;

  return ia - ib;
}

int main() {
  static int aa[mxN * 2];
  int n, a, b, tmp, max, k, i, j;

  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    aa[i * 2] = a * 2;
    aa[i * 2 + 1] = b * 2 + 1;
  }

  init_rand();

  for (j = 0; j < n * 2; j++) {
    i = rand_(j + 1);
    tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
  }

  qsort(aa, n * 2, sizeof *aa, compare);
  max = k = 0;

  for (i = 0; i < n * 2; i++) {
    if (max < (k += aa[i] % 2 == 0 ? 1 : -1)) max = k;
  }

  cout << max;
}
