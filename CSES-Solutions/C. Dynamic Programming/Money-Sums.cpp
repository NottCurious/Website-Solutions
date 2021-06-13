#include <bits/stdc++.h>
using namespace std;

const int mxX = 1e5;

int n, x, cnt, largest;
bool dp[mxX + 1];

int main(){
    cin >> n;

    dp[0] = true;
    for(int i = 0; i < n; i++){
        cin >> x;
        for(int j = mxX - x; j >= 0; j--)
            if(dp[j])
                dp[j + x] = true;
    }

    for(int i = 1; i <= mxX; i++){
        if(dp[i]){
            largest = i;
            cnt++;
        }
    }
    cout << cnt << endl;
    for(int i = 1; i <= mxX; i++)
        if(dp[i])
            printf("%d%c", i, (" \n")[i==largest]);
}
