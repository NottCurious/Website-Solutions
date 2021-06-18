#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int n, k, idx;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
    T;

int main() {
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    T.insert(i);
  }

  idx = k;

  while (T.size()) {
    idx %= T.size();
    int x = *T.find_by_order(idx);

    T.erase(x);

    printf("%d%c", x, (" \n")[T.size() == 0]);
    idx += k;
  }
}
