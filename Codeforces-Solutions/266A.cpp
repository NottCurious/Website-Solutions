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
	int n, cnt = 0;
	cin >> n;
	string s;
	cin >> s;

	for(int i = 0; i < n - 1; i++) {
		if(s[i] == s[i + 1])
			cnt++;
	}

	cout << cnt << end1;
}