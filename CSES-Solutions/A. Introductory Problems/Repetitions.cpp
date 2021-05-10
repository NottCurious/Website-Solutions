#include <iostream>
using namespace std;

#define ll long long
#define space " "
#define end1 "\n"

int main() {
    string s;
    int cur = 1, best = 1;
    cin >> s;

    for(int i = 1; i < s.size(); i++) {
      if(s[i] == s[i - 1])
        cur++;
      else {
        cur = 1;
      }

      best = max(best, cur);
    }

    cout << best;
}
