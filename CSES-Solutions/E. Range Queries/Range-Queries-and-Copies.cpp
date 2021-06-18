#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5 + 1;

struct Node {
  Node *l, *r;
  int lo, hi;
  ll sum;
  Node(int low, int high, int val)
      : l(nullptr), r(nullptr), lo(low), hi(high), sum(val) {}
  Node(Node* left, Node* right) : l(left), r(right), sum(0) {
    if (left) {
      sum += left->sum;
      lo = left->lo;
    }
    if (right) {
      sum += right->sum;
      hi = right->hi;
    }
  }
};

int n, q, type, k, a, b, x, cnt, t[mxN];
Node* seg[mxN];

Node* build(int l, int r) {
  if (l == r) return new Node(l, r, t[l]);
  int m = (l + r) / 2;
  return new Node(build(l, m), build(m + 1, r));
}

Node* update(Node* node, int idx, int val) {
  if (node->lo == node->hi) return new Node(idx, idx, val);
  int m = (node->lo + node->hi) / 2;
  if (idx <= m)
    return new Node(update(node->l, idx, val), node->r);
  else
    return new Node(node->l, update(node->r, idx, val));
}

ll query(Node* node, int l, int r) {
  if (l > node->hi || r < node->lo) return 0;
  if (l <= node->lo && node->hi <= r) return node->sum;
  return query(node->l, l, r) + query(node->r, l, r);
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> t[i];

  cnt = 1;
  seg[cnt++] = build(1, n);
  for (int i = 0; i < q; i++) {
    cin >> type >> k;
    if (type == 1) {
      cin >> a >> x;
      seg[k] = update(seg[k], a, x);
    } else if (type == 2) {
      cin >> a >> b;
      cout << query(seg[k], a, b) << endl;
    } else if (type == 3) {
      seg[cnt++] = new Node(seg[k]->l, seg[k]->r);
    }
  }
}
