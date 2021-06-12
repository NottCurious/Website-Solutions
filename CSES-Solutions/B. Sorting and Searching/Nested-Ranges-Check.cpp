#include <bits/stdc++.h>
using namespace std;

typedef array<int,3> triple;
const int mxN = 2e5 + 1;
const int SIZE = 2*mxN;

int n, ans[2][mxN], ds[SIZE];
triple ranges[mxN];
set<int> unique_vals;
map<int,int> mp;

void update(int idx, int val){
    for(int i = idx; i < SIZE; i += -i&i)   ds[i] += val;
}

int query(int idx){
    int cnt = 0;
    for(int i = idx; i > 0; i -= -i&i)
        cnt += ds[i];
    return cnt;
}

// Have to Use scanf and printf because of speed on a specific testcase

int main(){
    scanf("%d", &n);
    for(int i = 0, x, y; i < n; i++){
        scanf("%d %d", &x, &y);
        ranges[i] = {x, y, i};
        unique_vals.insert(x);
        unique_vals.insert(y);
    }
    sort(ranges, ranges+n, [](triple A, triple B){
        return (A[0] == B[0] ? A[1] > B[1] : A[0] < B[0]);
    });

    int val_id = 1;
    for(int x : unique_vals)
        mp[x] = val_id++;

    for(int i = n-1; i >= 0; i--){
        int y = mp[ranges[i][1]];
        int id = ranges[i][2];

        ans[0][id] = query(y);
        update(y, 1);
    }

    fill(ds, ds + SIZE, 0);
    for(int i = 0; i < n; i++){
        int y = mp[ranges[i][1]];
        int id = ranges[i][2];

        ans[1][id] = i - query(y - 1);
        update(y, 1);
    }

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++)
            printf("%d%c", (ans[i][j] ? 1 : 0), (" \n")[j==n-1]);
}
