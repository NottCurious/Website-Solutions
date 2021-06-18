#include <bits/stdc++.h>

using namespace std;
const int mxN = 2e5;

set<int> s;
set<int>::iterator f, c, b;
int n, x, a, best, ans[mxN];
struct light {
  int pos, id;
} l[mxN + 2];

int main() {
  scanf("%d %d", &x, &n);
  l[0] = {0, 0};
  l[n + 1] = {x, 1};
  s.insert(0);
  s.insert(x);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    l[i + 1] = {a, i + 2};
    s.insert(a);
  }

  sort(l, l + mxN + 2, [](light A, light B) { return A.pos < B.pos; });
  for (int i = 1; i <= mxN + 1; i++) best = max(best, l[i].pos - l[i - 1].pos);

  sort(l, l + mxN + 2, [](light A, light B) { return A.id > B.id; });
  for (int i = 0; i < n; i++) {
    ans[n - i - 1] = best;
    c = s.find(l[i].pos);
    f = next(c, 1);
    b = next(c, -1);
    best = max(best, *f - *b);
    s.erase(c);
  }

  for (int i = 0; i < n; i++) printf("%d%c", ans[i], (" \n")[i == n]);
}
