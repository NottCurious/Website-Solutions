#include <bits/stdc++.h>
using namespace std;

const int mxN = 8;

char c;
int ans;
bool b[mxN][mxN], input[mxN][mxN];

bool place(int x, int y) {
  bool yes = true;

  for (int i = 0; i < mxN; i++)
    if (b[x][i] || b[i][y]) yes = false;

  for (int i = 0; x - i >= 0 && y - i >= 0; i++)
    if (b[x - i][y - i]) yes = false;

  for (int i = 0; x - i >= 0 && y + i < mxN; i++)
    if (b[x - i][y + i]) yes = false;

  return yes;
}

bool check() {
  for (int i = 0; i < mxN; i++)
    for (int j = 0; j < mxN; j++)
      if (b[i][j] && input[i][j]) return false;

  return true;
}

void dfs(int i) {
  if (i == mxN) {
    if (check()) ans++;
    return;
  }
  for (int j = 0; j < mxN; j++) {
    if (place(i, j)) {
      b[i][j] = true;
      dfs(i + 1);
      b[i][j] = false;
    }
  }
}

int main() {
  for (int i = 0; i < mxN; i++) {
    for (int j = 0; j < mxN; j++) {
      cin >> c;
      input[i][j] = (c == '*');
    }
  }

  dfs(0);
  cout << ans;
}
