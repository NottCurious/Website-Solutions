#include <iostream>
#include <string>
using namespace std;

int t;

int main()
{
  cin >> t;

  string a[t];
  string ans[t];

  int i = 0;

  while(t--) {
    string s;
    cin >> s;

    if(s.size() <= 4) {
      a[i] = s;
      i++;
      continue;
    }

    int n = s.size();

    ans[n - s.size()] = s[0] + to_string(n - 2) + s[n - 1] << endl;
  }

  for(int i = 0; i < t; i++) {
    cout << ans[i] << endl;
  }
}
