#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5;
const int mxM = 100;
const ll mxMD = 1e9 + 7;

int n, m, x[mxN + 1];
ll ans, dp[mxN + 1][mxM + 1];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> x[i];

    if(x[1])
        dp[1][x[1]] = 1;
    else
        for(int i = 1; i <= m; i++)
            dp[1][i] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            if(j != 1)  dp[i][j] += dp[i - 1][j - 1];
            if(j != m)  dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] %= mxMD;
        }

        if(x[i])
            for(int j = 0; j <= m; j++)
                if(j != x[i])
                    dp[i][j] = 0;
    }

    for(int i= 1; i <= m; i++)
        ans = (ans + dp[n][i]) % mxMD;
    cout << ans;
}
