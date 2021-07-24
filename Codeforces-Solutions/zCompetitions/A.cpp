#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define end1 "\n"
#define space " "

void solve();
int countdigits(int);
int sum(string, int);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;

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

	int nsum = sum((string) n, countdigits(n));

	for(int i = 0; i <= n; i++) {
		diglen = countdigits(i);

		if(diglen == 1)
			if (i < nsum)
				cnt++;
			continue;

		if(sum((string) i, countdigits(i)) < nsum)
			cnt++;
	}

	cout << cnt << end1;
}

int countdigits(int num) {
	int cnt = 0;

	while(num > 0) {
		num = num / 10;
		cnt++;
	}

	return cnt;
}

int sum(string s, int n) {
	int sum = 0;

	for(int i = 0; i < n; i++) {
		sum = sum + (s[i] - '0');
	}

	return sum;
}