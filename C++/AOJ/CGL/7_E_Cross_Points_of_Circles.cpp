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

int ccw(Point p0, Point p1, Point p2)
{
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS)
        return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS)
        return CLOCKWISE;
    if (dot(a, b) < -EPS)
        return ONLINE_BACK;
    if (a.norm() < b.norm())
        return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersectPP(Point p1, Point p2, Point p3, Point p4)
{
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

// 線分の交差判定
bool intersect(Segment s1, Segment s2)
{
    return intersectPP(s1.p1, s1.p2, s2.p1, s2.p2);
}

// 線分が直行かを返す
bool isOrthogonal(Segment s1, Segment s2)
{
    return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

// 線分が平行かを返す
bool isParallel(Segment s1, Segment s2)
{
    return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

Point project(Segment s, Point p)
{
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
}

Point reflect(Segment s, Point p)
{
    return p + (project(s, p) - p) * 2.0;
}

// 線分の交点を求める
Point getCrossPoint(Segment s1, Segment s2)
{
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}

// 円と線分の交点を求める
pair<Point, Point> getCrossPoints(Circle c, Line l)
{
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
    double base = sqrt(c.r * c.r - norm(pr - c.c));
    return make_pair(pr + e * base, pr - e * base);
}

// 円と円の交点を求める
double arg(Vector p) { return atan2(p.y, p.x); }
Vector polar(double a, double r) { return Point(cos(r) * a, sin(r) * a); }

pair<Point, Point> getCrossPointsOfCircles(Circle c1, Circle c2)
{
    double d = abs(c1.c - c2.c);
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

double getDistancePP(Point a, Point b)
{
    return abs(a - b);
}

double getDistanceLP(Line l, Point p)
{
    return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

double getDistanceSP(Segment s, Point p)
{
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0)
        return abs(p - s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0)
        return abs(p - s.p2);
    return getDistanceLP(s, p);
}

double getDistance(Segment s1, Segment s2)
{
    if (intersect(s1, s2))
        return 0.0;
    double a = min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2));
    double b = min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2));
    return min(a, b);
}

int main(void)
{
    double cx, cy, r;
    cin >> cx >> cy >> r;

    Circle c1 = Circle(Point(cx, cy), r);

    cin >> cx >> cy >> r;
    Circle c2 = Circle(Point(cx, cy), r);

    pair<Point, Point> points = getCrossPointsOfCircles(c1, c2);

    Point p1 = points.first;
    Point p2 = points.second;

    cout << fixed << setprecision(10);

    if (p1.x == p2.x)
    {
        if (p1.y < p2.y)
        {
            cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
        }
        else
        {
            cout << p2.x << " " << p2.y << " " << p1.x << " " << p1.y << endl;
        }
    }
    else if (p1.x < p2.x)
    {
        cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
    }
    else
    {
        cout << p2.x << " " << p2.y << " " << p1.x << " " << p1.y << endl;
    }

    return 0;
}
