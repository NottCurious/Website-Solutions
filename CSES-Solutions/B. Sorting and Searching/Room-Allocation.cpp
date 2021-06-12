#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;

set<int> s;
int n, a, b, rooms, ans[mxN + 1];
struct query {int type, time, id; } queries[2 * mxN];

int main() {
  cin >> n;

  for(int i = 0; i < n; i++) {
    s.insert(i + 1);
    cin >> a >> b;

    queries[2 * i] = {0, a, i + 1};
    queries[2 * i + 1] = {1, b, i + 1};
  }

  sort(queries, queries+2*n, [](query A, query B){
      if(A.id == B.id)    return A.type < B.type;
      return A.time == B.time ? A.type < B.type : A.time < B.time;
  });

  for(int i = 0; i < 2 * n; i++) {
    if(queries[i].type == 0) {
      ans[queries[i].id] = *s.begin();
      s.erase(s.begin());
    } else if (queries[i].type == 1) {
      s.insert(ans[queries[i].id]);
    }
  }

  for(int i = 1; i <= n; i++)
    rooms = max(rooms, ans[i]);

  cout << rooms << endl;

  for(int i = 1; i <= n; i++) {
    printf("%d%c", ans[i], (" \n")[i==n]);
  }
}
