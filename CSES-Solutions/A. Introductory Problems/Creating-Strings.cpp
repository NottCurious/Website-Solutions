#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  char s[9];
  set<string> perms;

  cin >> s;

  n = strlen(s);
  sort(s, s+n);

  perms.insert(s);

  while(next_permutation(s, s+n))
    perms.insert(string(s, s+n));

  cout << perms.size() << endl;

  for(string perm : perms) {
    cout << perm << endl;
  }
}
