#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxMD = 1e9+7;

int n;
ll a, b, c;

ll fastpow(ll a, ll b, ll mod){
    ll res = 1;
    while(b > 0){
        if(b&1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        cout << fastpow(a, fastpow(b, c, mxMD - 1), mxMD) << endl;
    }
}
