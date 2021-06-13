#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+5;

int n, a, b, p[mxN], sz[mxN];
vector<int> G[mxN];

void dfs(int u = 1){
    sz[u] = 1;
    for(int v : G[u]){
        if(v != p[u]){
            p[v] = u;
            dfs(v);
            sz[u] += sz[v];
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs();

    for(int i = 1; i <= n; i++){
        bool centroid = true;

        if(p[i] != 0 && n-sz[i] > n/2)
            centroid = false;

        for(int v : G[i])
            if(v != p[i] && sz[v] > n/2)
                centroid = false;

        if(centroid){
            cout << i << endl;
            return 0;
        }
    }
}
