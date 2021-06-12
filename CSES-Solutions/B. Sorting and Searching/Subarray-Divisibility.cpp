#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5;

int n, pre, a, freq[mxN];
ll cnt;

int mod(int x){
    return (x % n + n) % n;
}

int main(){
    cin >> n;
    freq[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> a;
        pre = mod(pre + a);
        cnt += freq[pre];
        freq[pre]++;
    }
    cout << cnt;
}
