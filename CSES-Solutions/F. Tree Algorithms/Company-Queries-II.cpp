#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+1;
const int logN = 20;

int n, q, e, a, b, p[mxN][logN];
int timer, in[mxN], out[mxN];
vector<int> G[mxN];

void dfs(int u = 1, int par = 1){
    in[u] = ++timer;
    p[u][0] = par;
    for(int i = 1; i < logN; i++)
        p[u][i] = p[p[u][i-1]][i-1];
    for(int v : G[u])
        if(v != par)
            dfs(v, u);
    out[u] = ++timer;
}

bool ancestor(int u, int v){
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v){
    if(ancestor(u, v))  return u;
    if(ancestor(v, u))  return v;
    for(int i = logN-1; i >= 0; i--)
        if(!ancestor(p[u][i], v))
            u = p[u][i];
    return p[u][0];
}

int main(){
    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        cin >> e;
        G[e].push_back(i);
        G[i].push_back(e);
    }

    dfs();

    for(int s = 0; s < q; s++){
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}
