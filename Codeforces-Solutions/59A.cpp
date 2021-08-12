#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define end1 "\n"
#define space " "

void solve();
int bcountcase(string s);
string makeupper(string s);
string makelower(string s);


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

int countcase(string s) {
	int uppercnt = 0, lowcnt = 0;

	for(char c : s) {
		if (int(c) >= 65 && int(c) <= 90)
			uppercnt++;
		else
			lowcnt++;

	}

	int a = (uppercnt > lowcnt)? 0:1;

	return a;
}

string makelower(string s) {
	string retstring = "";

	for(char c : s) {
		if(c <= 65 && c >= 90) {
			retstring += char(int(c) + 32);
		}
		else {
			retstring += c;
		}
	}

	return retstring;
}

string makeupper(string s) {
	string retstring = "";

	for(char c : s) {
		if(c <= 122 && c >= 97) {
			retstring += char(int(c) + 32);
		}
		else {
			retstring += c;
		}
	}	

	return retstring;
}

void solve() {
	string s;
	cin >> s;

	int n = s.size();
	int a = countcase(s);

	if(a == 0) {
		s = makeupper(s);
		cout << s << endl;
	}
	else {
		s = makelower(s);
		cout << s << endl;
	}


}
