#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

const int mxN = 2e5;

int aa[mxN], bb[mxN];

void init_rand() {
    struct timeval tv;

    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;

    return bb[i] - bb[j];
}

int main() {
    static int ii[mxN];
    int n, i, j, tmp, t, k;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> aa[i] >> bb[i];
        ii[i] = i;
    }
    for (j = 0; j < n; j++) {
        i = rand_(j + 1);
        tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
    }
    qsort(ii, n, sizeof *ii, compare);
    t = 0, k = 0;
    for (i = 0; i < n; i++)
        if (t <= aa[ii[i]])
            t = bb[ii[i]], k++;
    cout << k;
    return 0;
}
