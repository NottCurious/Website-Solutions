#include <bits/stdc++.h>
using namespace std;

typedef array<int, 3> triple;
const int mxN = 2e5 + 1;

int n, q, a, b, x[mxN], ptr[mxN], ds[mxN], ans[mxN];
triple queries[mxN];
map<int, int> mp;
set<int> S;

void update(int idx, int val){
    for(int i = idx; i <= n; i += -i&i)
        ds[i] += val;
}

int query(int idx){
    int sum = 0;
    for(int i = idx; i > 0; i -= -i&i)
        sum += ds[i];
    return sum;
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> x[i];

    for(int i = n; i > 0; i--){
        if(mp[x[i]])
            ptr[i] = mp[x[i]];
        mp[x[i]] = i;
    }

    for(int i = 1; i <= n; i++){
        if(S.count(x[i]) == 0)
            update(i, 1);
        S.insert(x[i]);
    }

    for(int i = 0; i < q; i++){
        cin >> a >> b;
        queries[i] = {a, b, i};
    }
    sort(queries, queries+q);

    int l = 1;
    for(int i = 0; i < q; i++){
        while(l < queries[i][0]){
            if(ptr[l])
                update(ptr[l], 1);
            l++;
        }
        ans[queries[i][2]] = query(queries[i][1]) - query(queries[i][0] - 1);
    }

    for(int i = 0; i < q; i++)
        cout << ans[i] << endl;
}
