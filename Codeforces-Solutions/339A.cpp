#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define end1 "\n"
#define space " "

void solve();
void insertionSort(int[], int);

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

	int n;

	if(s.size() % 2 == 0)
		n = s.size() / 2;
	else
		n = (int) ((s.size() + 1) / 2);

	int a[n], j = 0;

	for(int i = 0; i < s.size(); i += 2) {
		a[j] = s[i] - '0';
		j += 1;
	}

	sort(a, a + n);

	cout << a[0];

	for(int i = 1; i < n; i++) {
		cout << '+' << a[i];
	}
}
