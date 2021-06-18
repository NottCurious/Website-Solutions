#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
const int mxN = 2e5;

int n, p, x[mxN + 1];
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
    T;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    T.insert(i);
  }

  for (int i = 0; i < n; i++) {
    cin >> p;
    printf("%d%c", x[*T.find_by_order(p - 1)], (" \n")[i == n - 1]);
    T.erase(T.find_by_order(p - 1));
  }
}
