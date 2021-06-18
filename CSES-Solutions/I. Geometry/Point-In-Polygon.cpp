#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e3 + 1;

struct Point {
  int x, y;
  void read() { cin >> x >> y; }
  Point operator+(const Point& b) const { return Point{x + b.x, y + b.y}; }
  Point operator-(const Point& b) const { return Point{x - b.x, y - b.y}; }
  ll operator*(const Point& b) const { return (ll)x * b.y - (ll)y * b.x; }
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

int n, m;
Point P[mxN];

bool pointlineintersect(Point P1, Point P2, Point P3) {
  if (P2.cross(P1, P3) != 0) return false;
  return (min(P2.x, P3.x) <= P1.x && P1.x <= max(P2.x, P3.x)) &&
         (min(P2.y, P3.y) <= P1.y && P1.y <= max(P2.y, P3.y));
}

void pointinpolygon() {
  int cnt = 0;
  bool boundary = false;
  for (int i = 1; i <= n; i++) {
    int j = (i == n ? 1 : i + 1);
    if (pointlineintersect(P[0], P[i], P[j])) boundary = true;

    if (P[i].x <= P[0].x && P[0].x < P[j].x && P[0].cross(P[i], P[j]) < 0)
      cnt++;
    else if (P[j].x <= P[0].x && P[0].x < P[i].x && P[0].cross(P[j], P[i]) < 0)
      cnt++;
  }

  if (boundary)
    cout << "BOUNDARY" << endl;
  else if (cnt & 1)
    cout << "INSIDE" << endl;
  else
    cout << "OUTSIDE" << endl;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) P[i].read();
  for (int i = 0; i < m; i++) {
    P[0].read();
    pointinpolygon();
  }
}
