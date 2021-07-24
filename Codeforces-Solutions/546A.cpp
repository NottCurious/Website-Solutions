#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define end1 "\n"
#define space " "

void solve();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;

	while(t--) {
		solve();

		cout << end1;
	}

	cerr << "time taken: " << (float) clock() / CLOCKS_PER_SEC << " s" << end1;
	return 0;
}

void solve() {
	int k, n, w;
	cin >> k >> n >> w;
	int total = (k) * (((w) * (w + 1)) / 2);

	if(total - n <= 0)
		cout << 0 << end1;
	else
		cout << total - n;
}