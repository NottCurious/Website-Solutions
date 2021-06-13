#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+1;

int n, a, b, last, dist[mxN];
vector<int> G[mxN];

void dfs(int u, int p = 0){
    for(int v : G[u]){
        if(v != p){
            dist[v] = dist[u]+1;
            dfs(v, u);
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

    dfs(1);
    for(int i = 1; i <= n; i++)
        if(dist[i] > dist[last])
            last = i;
    dist[last] = 0;
    dfs(last);
    for(int i = 1; i <= n; i++)
        if(dist[i] > dist[last])
            last = i;
    cout << dist[last] << endl;
}
