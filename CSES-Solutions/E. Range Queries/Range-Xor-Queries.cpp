#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5;

int n, q, a, b;
ll x[mxN + 1];

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
        x[i] ^= x[i - 1];
    }
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        cout << (ll) (x[b] ^ x[a - 1]) << endl;
    }
}
