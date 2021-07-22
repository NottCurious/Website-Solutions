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
	string s;
	cin >> s;

	if((int) s[0] >= 97)
		s[0] = s[0] - 32;

	cout << s;
}