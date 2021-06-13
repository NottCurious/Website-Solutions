#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<int, int> pii;

const int mxN = 2e5 + 1;
int n, a[mxN], b[mxN];
ll p[mxN], dp[2 * mxN];
struct project {int time, id, type;} times[2 * mxN];
map<int,int> mp;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> p[i];
        times[2 * i] = {a[i], i, 0};
        times[2 * i + 1] = {b[i], i, 1};
    }

    sort(times + 2, times + 2 * n + 2, [](project A, project B){
        return A.time == B.time ? A.id < B.id : A.time < B.time;
    });

    for(int i = 2; i <= 2 * n + 1; i++)
        if(!mp[times[i].time])
            mp[times[i].time] = i;

    for(int i = 2; i <= 2 * n + 1; i++){
        if(times[i].type == 0)  dp[i] = dp[i - 1];
        else dp[i] = max(dp[i - 1], dp[mp[a[times[i].id]] - 1] + p[times[i].id]);
    }
    cout << dp[2 * n + 1];
}
