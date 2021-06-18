#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 1;
const int logN = 20;

int n, q, a, b, p[mxN][logN];
int timer, d[mxN], in[mxN], out[mxN];
vector<int> G[mxN];

void dfs(int u = 1, int par = 1) {
  in[u] = ++timer;
  d[u] = d[par] + 1;
  p[u][0] = par;
  for (int i = 1; i < logN; i++) p[u][i] = p[p[u][i - 1]][i - 1];
  for (int v : G[u])
    if (v != par) dfs(v, u);
  out[u] = ++timer;
}

bool ancestor(int u, int v) { return in[u] <= in[v] && out[u] >= out[v]; }

int lca(int u, int v) {
  if (ancestor(u, v)) return u;
  if (ancestor(v, u)) return v;
  for (int i = logN - 1; i >= 0; i--)
    if (!ancestor(p[u][i], v)) u = p[u][i];
  return p[u][0];
}

int main() {
  cin >> n >> q;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs();

  for (int s = 0; s < q; s++) {
    cin >> a >> b;
    cout << d[a] + d[b] - 2 * d[lca(a, b)] << endl;
  }
}
