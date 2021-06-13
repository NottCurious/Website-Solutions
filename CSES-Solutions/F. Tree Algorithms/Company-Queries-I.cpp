#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+1;
const int logK = 20;

int n, q, x, k, p[mxN][logK];

int main(){
    cin >> n >> q;
    for(int i = 2; i <= n; i++)
        cin >> p[i][0];
    for(int j = 1; j < logK; j++)
        for(int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j-1]][j-1];

    for(int s = 0; s < q; s++){
        cin >> x >> k;
        for(int i = 0; i < logK; i++)
            if(k&(1<<i))
                x = p[x][i];
        cout << (x ? x : -1) << endl;
    }
}
