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
using std::setprecision;
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

int ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS) return CLOCKWISE;
    if (dot(a, b) < -EPS) return ONLINE_BACK;
    if (a.norm() < b.norm() )return ONLINE_FRONT;
    return ON_SEGMENT;
}

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
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p-s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p-s.p2);
    return getDistanceLP(s, p);
}

double getDistanceSS(Segment s1, Segment s2)
{
    return 0;
}

int main(void)
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    int q;
    cin >> q;

    Point p1 = Point(x1, y1);
    Point p2 = Point(x2, y2);

    double x3, y3;
    for (int i = 0; i < q; i++)
    {
        cin >> x3 >> y3;
        

        Point p3 = Point(x3, y3);
        auto ans = ccw(p1, p2, p3);
        string s;
        switch (ans) {
            case COUNTER_CLOCKWISE:
                s = "COUNTER_CLOCKWISE";
                break;
            case CLOCKWISE:
                s = "CLOCKWISE";
                break;
            case ONLINE_BACK:
                s = "ONLINE_BACK";
                break;
            case ONLINE_FRONT:
                s = "ONLINE_FRONT";
                break;
            case ON_SEGMENT:
                s = "ON_SEGMENT";
                break;
            default:
                break;
        }
        cout << fixed << setprecision(10);
        cout << s << endl;
    }
    return 0;
}
