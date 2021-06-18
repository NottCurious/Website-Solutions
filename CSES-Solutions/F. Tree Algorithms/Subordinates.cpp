#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;

int n, p[mxN + 1], sz[mxN + 1];
vector<int> G[mxN + 1];

void dfs(int u) {
  sz[u] = 1;
  for (int v : G[u]) {
    dfs(v);
    sz[u] += sz[v];
  }
}

int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    G[p[i]].push_back(i);
  }

  dfs(1);

  for (int i = 1; i <= n; i++) printf("%d%c", sz[i] - 1, (" \n")[i == n]);
}
