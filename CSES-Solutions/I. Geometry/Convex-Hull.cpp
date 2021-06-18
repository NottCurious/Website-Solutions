#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5 + 5;

struct Point {
  int x, y;
  void read() { cin >> x >> y; }
  Point operator+(const Point& b) const { return Point{x + b.x, y + b.y}; }
  Point operator-(const Point& b) const { return Point{x - b.x, y - b.y}; }
  ll operator*(const Point& b) const { return (ll)x * b.y - (ll)y * b.x; }
  bool operator<(const Point& b) const { return x == b.x ? y < b.y : x < b.x; }
  void operator+=(const Point& b) {
    x += b.x;
    y += b.y;
  }
  void operator-=(const Point& b) {
    x -= b.x;
    y -= b.y;
  }
  void operator*=(const int k) {
    x *= k;
    y *= k;
  }

  ll cross(const Point& b, const Point& c) const {
    return (b - *this) * (c - *this);
  }
};

int n, s;
Point P[mxN];
vector<Point> hull;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) P[i].read();
  sort(P, P + n);

  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < n; i++) {
      while ((int)hull.size() - s >= 2) {
        Point P1 = hull[hull.size() - 2];
        Point P2 = hull[hull.size() - 1];
        if (P1.cross(P2, P[i]) <= 0) break;
        hull.pop_back();
      }
      hull.push_back(P[i]);
    }
    hull.pop_back();
    s = hull.size();
    reverse(P, P + n);
  }

  cout << s << endl;
  for (Point h : hull) cout << h.x << " " << h.y << endl;
}
