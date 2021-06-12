#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 5;

int n, m, cnt, x[mxN], pos[mxN];

void update(int a, int b) {
  if (pos[x[a] - 1] <= pos[x[a]] && b < pos[x[a] - 1]) cnt++;
  if (pos[x[a] - 1] > pos[x[a]] && b >= pos[x[a] - 1]) cnt--;
  if (pos[x[a] + 1] >= pos[x[a]] && b > pos[x[a] + 1]) cnt++;
  if (pos[x[a] + 1] < pos[x[a]] && b <= pos[x[a] + 1]) cnt--;
  pos[x[a]] = b;

  if (pos[x[b] - 1] <= pos[x[b]] && a < pos[x[b] - 1]) cnt++;
  if (pos[x[b] - 1] > pos[x[b]] && a >= pos[x[b] - 1]) cnt--;
  if (pos[x[b] + 1] >= pos[x[b]] && a > pos[x[b] + 1]) cnt++;
  if (pos[x[b] + 1] < pos[x[b]] && a <= pos[x[b] + 1]) cnt--;
  pos[x[b]] = a;

  swap(x[a], x[b]);
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    pos[x[i]] = i;
  }
  pos[n + 1] = n + 1;

  cnt = 0; 
  for (int i = 1, ptr; i <= n; i++) {
    if (ptr > pos[i])
      cnt++;
    ptr = pos[i];
  }

  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b;
    update(a, b);
    cout << cnt << endl;
  }
}
