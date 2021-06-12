#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e3 + 1;

int n;
ll x[mxN], y[mxN], ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    x[n] = x[0]; y[n] = y[0];

    for(int i = 0; i < n; i++){
        ans += x[i] * y[i+1];
        ans -= y[i] * x[i+1];
    }
    cout << abs(ans);
}
