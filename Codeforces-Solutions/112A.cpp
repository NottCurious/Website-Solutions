#include <iostream>
#include <string>
using namespace std;

void lowerCase(string& strToConvert) {
	for(int i = 0; i < strToConvert.length(); i++) {
		strToConvert[i] = tolower(strToConvert[i]);
	}
}

int main() {
	string a, b;
	cin >> a >> b;

	lowerCase(a);
	lowerCase(b);

	if(a > b)
		cout << 1;
	else if(a == b)
		cout << 0;
	else
		cout << -1;
}

