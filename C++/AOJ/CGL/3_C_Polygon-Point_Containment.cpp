#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
typedef long long llong;
#define MAX 100000
#define INF (1 << 30)
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
typedef pair<int, int> pi;
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

// 点
class Point
{
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y){};

    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
    Point operator*(double a) { return Point(x * a, y * a); }
    Point operator/(double a) { return Point(x / a, y / a); }

    double abs() { return sqrt(norm()); }
    double norm() { return x * x + y * y; }

    bool operator<(const Point &p) const
    {
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator==(const Point &p) const
    {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
};

// ベクトル
typedef Point Vector;

// 線分
struct Segment
{
    Point p1, p2;
    Segment(Point a, Point b)
    {
        p1 = a;
        p2 = b;
    }
};

// 直線
typedef Segment Line;

// 円
class Circle
{
public:
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};

// 多角形
typedef vector<Point> Polygon;

// ベクトルの内積の計算
double dot(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}

// ベクトルの外積の計算
double cross(Vector a, Vector b)
{
    return a.x * b.y - a.y * b.x;
}

double norm(Vector a) { return a.x * a.x + a.y * a.y; }
double abs(Vector a) { return sqrt(norm(a)); }

int contains(Polygon g, Point p)
{
    int n = g.size();
    bool x = false;
    for (int i = 0; i < n; i++) {
        Point a = g[i] - p, b = g[(i + 1) % n] - p;
        if (abs(cross(a, b)) < EPS && dot(a,b) < EPS) return 1;
        if (a.y > b.y) swap(a, b);
        if (a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x; 
    }
    return (x ? 2 : 0);
}

int main(void)
{
    int g;
    cin >> g;
    
    Polygon polygon;
    double x,y;
    for (int i = 0; i < g; i++) {
        cin >> x >> y;
        polygon.push_back(Point(x,y));
    }

    int q;
    cin >> q;
    
    int ans;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        ans = contains(polygon, Point(x, y));
        cout << ans << endl;
    }

    return 0;
}
