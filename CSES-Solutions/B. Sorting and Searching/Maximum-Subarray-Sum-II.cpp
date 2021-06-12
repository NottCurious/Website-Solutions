#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5;

int main() {
    static ll xx[mxN + 1];
    static int qq[mxN];
    int n, a, b, i, head, cnt;
    ll x, x_;

    cin >> n >> a >> b;
    x = 0;
    for (i = 1; i <= n; i++)
        cin >> xx[i], xx[i] = x += xx[i];
    head = cnt = 0;
    x = -3e14;
    for (i = a; i <= n; i++) {
        while (cnt && xx[qq[head + cnt - 1]] >= xx[i - a])
            cnt--;
        qq[head + cnt++] = i - a;
        if (x < (x_ = xx[i] - xx[qq[head]]))
            x = x_;
        if (qq[head] == i - b)
            head++, cnt--;
    }
    cout << x;
    return 0;
}
