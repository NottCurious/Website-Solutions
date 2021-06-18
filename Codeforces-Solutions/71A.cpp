#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;

  string a[t];
  int i = 0;

  while (t--) {
    string s;
    cin >> s;

    if (s.size() <= 4) {
      a[i] = s;
      i++;
      continue;
    }

    int n = s.size();

    // a[i] = s[0] + to_string(n - 2) + s[n - 1];
    // i++;

    cout << s[0] + to_string(n - 2) + s[n - 1] << endl;
  }

  // for(int j = 0; j < i; j++) {
  //   cout << a[j] << endl;
  // }
}
