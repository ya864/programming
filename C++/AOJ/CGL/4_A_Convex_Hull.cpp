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

    bool operator<(Point p) 
    {
        return y * 1e10 + x < p.y * 1e10 + p.x;
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

int ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS) return CLOCKWISE;
    if (dot(a, b) < -EPS) return ONLINE_BACK;
    if (a.norm() < b.norm() )return ONLINE_FRONT;
    return ON_SEGMENT;
}

Polygon andrewScan(Polygon s) {
    Polygon u, l;
    if ( s.size() < 3 ) return s;
    // x, y を基準にソート
    sort(s.begin(), s.end());
    // x が小さいものから2つ u に追加
    u.push_back(s[0]);
    u.push_back(s[1]);
    // x が大きいものから2つ l に追加
    l.push_back(s[s.size() - 1]);
    l.push_back(s[s.size() - 2]);

    // 凸包の上部を生成
    for (int i = 2; i < s.size(); i++){
        for (int n = u.size(); n >= 2; n--) {
            if (ccw(u[n-2], u[n-1], s[i]) != COUNTER_CLOCKWISE){
                break;
            }
            u.pop_back();
        }
        u.push_back(s[i]);
    }

    // 凸包の下部を生成
    for (int i = s.size() - 3; i >= 0; i--) {
        for (int n = l.size(); n >= 2; n--) {
            if (ccw(l[n-2], l[n-1], s[i]) != COUNTER_CLOCKWISE) {
                break;
            }
            l.pop_back();
        }
        l.push_back(s[i]);
    }

    // 時計回りになるように凸包の点の列を生成
    reverse(l.begin(), l.end());
    for(int i = u.size() - 2; i >= 1; i--) l.push_back(u[i]);

    return l;
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

    Polygon p = andrewScan(polygon);

    cout << p.size() << endl;
    for (int i = 0; i < p.size(); i++) {
        cout << p[i].x << " " << p[i].y << endl;
    }

    return 0;
}
