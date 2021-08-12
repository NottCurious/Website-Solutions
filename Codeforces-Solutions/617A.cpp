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
	int x, cnt = 0;
	cin >> x;

	while (x > 0) {
		if(x >= 5) {
			x -= 5;
			cnt++;
		}
		else if(x >= 4) {
			x -= 4;
			cnt++;
		}
		else if(x >= 3) {
			x -= 3;
			cnt++;
		}
		else if(x >= 2) {
			x -= 2;
			cnt++;
		}
		else if(x >= 1) {
			x -= 1;
			cnt++;
		}
	}

	cout << cnt << endl;

}