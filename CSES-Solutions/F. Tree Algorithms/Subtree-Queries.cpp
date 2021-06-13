#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN = 2e5+1;

int n, q, a, b, t, s, timer;
int in[mxN], out[mxN];
ll k[mxN], ds[2*mxN];
vector<int> G[mxN];

void update(int idx, ll val){
    for(int i = idx; i < 2*mxN; i += i&-i)
        ds[i] += val;
}

ll query(int idx){
    ll sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        sum += ds[i];
    return sum;
}

void dfs(int u, int p = 0){
    in[u] = ++timer;
    for(int v : G[u])
        if(v != p)
            dfs(v, u);
    out[u] = ++timer;
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> k[i];

    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    timer = 0;
    dfs(1);

    for(int i = 1; i <= n; i++)
        update(out[i], k[i]);

    for(int u = 0; u < q; u++){
        cin >> t >> s;
        if(t == 1){
            update(out[s], -k[s]);
            cin >> k[s];
            update(out[s], k[s]);
        } else if(t == 2){
            printf("%lld\n", query(out[s])-query(in[s]));
        }
    }
}
