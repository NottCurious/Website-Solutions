#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxN = 2e5+1;

int n, q, a, b, t, s;
int timer, in[maxN], out[maxN];
ll x, v[maxN], ds[2*maxN];
vector<int> G[maxN];

void update(int idx, ll val){
    for(int i = idx; i <= timer; i += -i&i)
        ds[i] += val;
}

ll query(int idx){
    ll sum = 0;
    for(int i = idx; i > 0; i -= -i&i)
        sum += ds[i];
    return sum;
}

void dfs(int u = 1, int p = 0){
    in[u] = ++timer;
    for(int c : G[u])
        if(c != p)
            dfs(c, u);
    out[u] = ++timer;
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs();
    for(int i = 1; i <= n; i++){
        update(in[i], v[i]);
        update(out[i], -v[i]);
    }

    for(int u = 0; u < q; u++){
        cin >> t >> s;
        if(t == 1){
            cin >> x;
            update(in[s], -v[s]);
            update(out[s], v[s]);
            update(in[s], x);
            update(out[s], -x);
            v[s] = x;
        } else if(t == 2){
            cout << query(in[s]) << endl;
        }
    }
}
