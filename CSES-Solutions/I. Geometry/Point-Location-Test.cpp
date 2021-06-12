#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Point {
    int x, y;
    void read(){cin >> x >> y;}
    Point operator +(const Point& b) const { return Point{x+b.x, y+b.y}; }
    Point operator -(const Point& b) const { return Point{x-b.x, y-b.y}; }
    ll operator *(const Point& b) const { return (ll) x * b.y - (ll) y * b.x; }
    void operator +=(const Point& b) { x += b.x; y += b.y; }
    void operator -=(const Point &b) { x -= b.x; y -= b.y; }
    void operator *=(const int k) { x *= k; y *= k; }

    ll cross(const Point& b, const Point& c) const {
        return (b - *this) * (c - *this);
    }
};

int t;
Point P[3];

int main(){
    cin >> t;
    for(int j = 0; j < t; j++){
        for(int i = 0; i < 3; i++)
            P[i].read();

        ll cross = P[0].cross(P[1], P[2]);
        if(cross < 0)       cout << "RIGHT" << endl;
        else if(cross > 0)  cout << "LEFT" << endl;
        else                cout << "TOUCH" << endl;
    }
}
