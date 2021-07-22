#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define end1 "\n"
#define space " "

void solve();
bool checkVector(vector<char>, char);

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

	for(int i = 0; i < n; i++) {
		
	}
}

bool checkVector(vector<char> vc, char c) {
	for(char oldchar : vc) {
		if(oldchar == c)
			return false;
	}

	return true;
}