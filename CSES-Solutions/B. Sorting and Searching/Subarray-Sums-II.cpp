#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll x, a, cnt, pre;
map<ll,int> freq;

int main(){
    cin >> n >> x;
    freq[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> a;
        pre += a;
        cnt += freq[pre - x];
        freq[pre]++;
    }
    cout << cnt;
}
