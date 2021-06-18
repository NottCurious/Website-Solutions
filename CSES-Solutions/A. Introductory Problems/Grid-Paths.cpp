#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 7;
int ans;
char c[mxN * mxN + 1];
bool vis[mxN + 1][mxN + 1];

bool inbounds(int x, int y) { return 1 <= x && x <= mxN && 1 <= y && y <= mxN; }

void dfs(int x, int y, int i) {
  if (i == mxN * mxN - 1 || (x == mxN && y == 1)) {
    ans += (i == mxN * mxN - 1 && (x == mxN && y == 1));
    return;
  }

  if ((!inbounds(x + 1, y) || vis[x + 1][y]) &&
      (!inbounds(x - 1, y) || vis[x - 1][y]))
    if (inbounds(x, y - 1) && !vis[x][y - 1] && inbounds(x, y + 1) &&
        !vis[x][y + 1])
      return;
  if ((!inbounds(x, y + 1) || vis[x][y + 1]) &&
      (!inbounds(x, y - 1) || vis[x][y - 1]))
    if (inbounds(x + 1, y) && !vis[x + 1][y] && inbounds(x - 1, y) &&
        !vis[x - 1][y])
      return;

  vis[x][y] = true;
  if (c[i] == 'D' || c[i] == '?')
    if (inbounds(x + 1, y) && !vis[x + 1][y]) dfs(x + 1, y, i + 1);

  if (c[i] == 'U' || c[i] == '?')
    if (inbounds(x - 1, y) && !vis[x - 1][y]) dfs(x - 1, y, i + 1);

  if (c[i] == 'R' || c[i] == '?')
    if (inbounds(x, y + 1) && !vis[x][y + 1]) dfs(x, y + 1, i + 1);

  if (c[i] == 'L' || c[i] == '?')
    if (inbounds(x, y - 1) && !vis[x][y - 1]) dfs(x, y - 1, i + 1);

  vis[x][y] = false;
}

int main() {
  cin >> c;
  dfs(1, 1, 0);
  cout << ans;
}
