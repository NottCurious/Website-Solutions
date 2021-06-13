#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxX = 1e6;
const ll mxMD = 1e9 + 7;

int n, x, c;
ll dp[mxX + 1];

int main(){
    cin >> n >> x;

    dp[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> c;
        for(int j = 0; j <= x - c; j++)
            dp[j + c] = (dp[j + c] + dp[j]) % mxMD;
    }

    cout << dp[x];
}
