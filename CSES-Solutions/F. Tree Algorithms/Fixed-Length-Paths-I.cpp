#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN = 2e5+1;

int n, k, deepest, sz[mxN], cnt[mxN];
bool vis[mxN];
ll ans;
vector<int> G[mxN];

int getSize(int u = 1, int p = -1){
    sz[u] = 1;
    for(int v : G[u])
        if(v != p && !vis[v])
            sz[u] += getSize(v, u);

    return sz[u];
}

int centroid(int u, int p, int n){
    for(int v : G[u])
        if(v != p && !vis[v] && sz[v] > n/2)
            return centroid(v, u, n);

    return u;
}

void dfs(int u, int p, bool t, int d = 1){
    if(d > k)   return;

    deepest = max(deepest, d);
    if(t)       cnt[d]++;
    else        ans += cnt[k-d];

    for(int v : G[u])
        if(v != p && !vis[v])
            dfs(v, u, t, d+1);
}

void solve(int u = 1){
    int c = centroid(u, -1, getSize(u));
    vis[c] = true;
    deepest = 0;

    for(int v : G[c]){
        if(!vis[v]){
            dfs(v, c, false);
            dfs(v, c, true);
        }
    }
    fill(cnt+1, cnt+deepest+1, 0);

    for(int v : G[c])
        if(!vis[v])
            solve(v);
}

int main(){
    cin >> n >> k;
    for(int i = 0, a, b; i < n-1; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cnt[0] = 1;
    solve();
    cout << ans << endl;
}
