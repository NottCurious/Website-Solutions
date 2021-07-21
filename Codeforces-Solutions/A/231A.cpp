#include <iostream>
using namespace std;

int main() {
	int p, v, t, test, cnt = 0;
	cin >> test;

	while(test--) {
		cin >> p >> v >> t;

		if(p + v + t >= 2)
			cnt++;
	}

	cout << cnt;
}