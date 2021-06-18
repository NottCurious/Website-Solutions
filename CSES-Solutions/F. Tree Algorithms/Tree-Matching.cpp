#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 1;

int n, a, b, cnt;
bool used[mxN];
vector<int> G[mxN];

void dfs(int u = 1, int par = 0) {
  for (int v : G[u])
    if (v != par) dfs(v, u);

  if (!used[par] && !used[u] && par != 0) {
    used[par] = used[u] = true;
    cnt++;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs();
  cout << cnt << endl;
}
