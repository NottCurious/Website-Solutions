#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int mxN = 5e3;

int n, x, v, r;
pii a[mxN];

int main(){
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        cin >> v;
        a[i] = {v, i + 1};
    }

    sort(a, a + n);
    for(int i = 0; i < n; i++){
        v = x - a[i].first;
        r = n - 1;
        for(int l = i + 1; l < r; l++){
            while(l + 1 < r && a[l].first + a[r].first > v)   r--;
            if(a[l].first + a[r].first == v){
                cout << a[i].second << " " << a[l].second << " " << a[r].second;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
