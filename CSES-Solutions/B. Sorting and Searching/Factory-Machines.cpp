#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5;
static int aa[mxN];
int n, k, i;
ll lower, upper, t, cnt;

int main() {
    cin >> n >> k;

    for (i = 0; i < n; i++)
        cin >> aa[i];

    lower = 0, upper = 2e18;

    while (upper - lower > 1) {
        t = (lower + upper) / 2;
        cnt = 0;
        for (i = 0; i < n; i++)
            if ((cnt += t / aa[i]) >= k)
                break;
        if (cnt >= k)
            upper = t;
        else
            lower = t;
    }
    cout << upper;
    return 0;
}
