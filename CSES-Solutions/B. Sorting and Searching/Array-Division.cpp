#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5;
static int aa[mxN];
int n, k, i;
ll sum, lower, upper, x;

int count(int *aa, int n, ll x) {
    ll a;
    int i, k;

    a = 0;
    k = 0;
    for (i = 0; i < n; i++) {
        if (a + aa[i] > x) {
            a = 0;
            k++;
        }
        a += aa[i];
    }
    return k + 1;
}

int main() {
    int max;
    
    cin >> n >> k;
    max = 0, sum = 0;
    for (i = 0; i < n; i++) {
        cin >> aa[i];
        sum += aa[i];
        if (max < aa[i])
            max = aa[i];
    }
    lower = max - 1, upper = sum;
    while (upper - lower > 1) {
        x = (lower + upper) / 2;
        if (count(aa, n, x) <= k)
            upper = x;
        else
            lower = x;
    }
    cout << upper;
    return 0;
}
