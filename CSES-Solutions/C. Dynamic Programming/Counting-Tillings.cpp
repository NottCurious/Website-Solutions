#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 11;
const int mxM = 1e3 + 1;
const ll mxMD = 1e9 + 7;

int n, m;
ll dp[mxN][mxM][1 << mxN];

int main(){
    cin >> n >> m;

    dp[n][0][0] = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < (1 << n); j++)
            dp[0][i][j << 1] = dp[n][i - 1][j];

        for(int j = 1; j <= n; j++){
            int x = 1<<(j - 1);
            int y = 1 << j;
            for(int mask = 0; mask < (1<<(n + 1)); mask++){
                dp[j - 1][i][mask] %= mxMD;
                if((mask & x) && (mask & y))    continue;
                if(mask & x)                  dp[j][i][mask ^ x] += dp[j - 1][i][mask];
                else if(mask & y)             dp[j][i][mask ^ y] += dp[j - 1][i][mask];
                else {
                    dp[j][i][mask ^ x] += dp[j - 1][i][mask];
                    dp[j][i][mask ^ y] += dp[j - 1][i][mask];
                }
            }
        }
    }

    cout << dp[n][m][0] % mxMD;
}
