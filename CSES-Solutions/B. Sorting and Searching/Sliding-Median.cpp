#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> pii;
const int mxN = 2e5;

int n, k, x[mxN];
tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>
    T;

int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> x[i];
    T.insert({x[i], i});
  }

  printf("%d%c", (*T.find_by_order((k - 1) / 2)).first, (" \n")[n == k]);

  for (int i = k; i < n; i++) {
    cin >> x[i];
    T.insert({x[i], i});
    T.erase({x[i - k], i - k});
    printf("%d%c", (*T.find_by_order((k - 1) / 2)).first, (" \n")[i == n - 1]);
  }
}
