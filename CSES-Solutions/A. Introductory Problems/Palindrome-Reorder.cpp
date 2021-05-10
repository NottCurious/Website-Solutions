#include <iostream>
#include <cstring>
using namespace std;

int main() {
  char s[1000001];
  int n, odd, freq[26];

  cin >> s;

  n = strlen(s);

  for(int i = 0; i < n; i++) {
    freq[(int) (s[i]-'A')]++;
  }

  odd = -1;

  for(int i = 0; i < 26; i++) {
    if(freq[i] & 1) {
      if(odd != -1) {
        cout << "NO SOLUTION" << endl;
        return 0;
      }
      else {
        odd = i;
      }
    }
  }

  for(int i = 0; i < 26; i++) {
    for(int j = 0; j < freq[i] / 2; j++) {
      cout << (char) (i + 'A');
    }
  }

  if(odd != -1) {
    cout << (char) (odd + 'A');
  }

  for(int i = 25; i >= 0; i--) {
    for(int j = 0; j < freq[i] / 2; j++) {
      cout << (char) (i + 'A');
    }
  }
}
