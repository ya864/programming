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
// 端点の種類
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

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

class EndPoint {
    public:
    Point p;
    int seg, st; // 入力線分のID, 端点の種類
    EndPoint() {}
    EndPoint(Point p, int seg, int st): p(p), seg(seg), st(st) {}

    bool operator < (const EndPoint &ep) const {
        // y 座標が小さい順に整列
        if (p.y == ep.p.y ) {
            // y が同一の場合は、下端点、左端点、右端点、上端点の順に並べる
            return st < ep.st;
        } else {
            return p.y < ep.p.y;
        }
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

// 端点のリスト
EndPoint EP[2 * 100000];

// 線分交差問題:マンハッタン幾何
int manhattanIntersection(vector<Segment> S) {
    int n = S.size();

    for (int i = 0, k = 0; i < n; i++ ) {
        // 端点 p1, p2 が左下を基準に並ぶように調整
        if (S[i].p1.y == S[i].p2.y) {
            if (S[i].p1.x > S[i].p2.x) swap(S[i].p1, S[i].p2);
        } else if (S[i].p1.y > S[i].p2.y) {
            swap(S[i].p1, S[i].p2);
        }


        if (S[i].p1.y == S[i].p2.y) {
            // 水平線分を端点リストに追加
            EP[k++] = EndPoint(S[i].p1, i, LEFT);
            EP[k++] = EndPoint(S[i].p2, i, RIGHT);
        } else {
            //垂直線分を端点リストに追加
            EP[k++] = EndPoint(S[i].p1, i, BOTTOM);
            EP[k++] = EndPoint(S[i].p2, i, TOP);
        }
    }
    
    // 端点の y 座標に関して照準に整列
    sort(EP, EP + (2 * n));

    // 二分探索木
    set<int> BT;
    // 番兵
    BT.insert(1000000001);
    int cnt = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (EP[i].st == TOP) {
            // 上端点を削除
            BT.erase(EP[i].p.x);
        } else if (EP[i].st == BOTTOM) {
            // 下端点を追加
            BT.insert(EP[i].p.x);
        } else if (EP[i].st == LEFT) {
            // 0(log n)
            set<int>::iterator b = BT.lower_bound(S[EP[i].seg].p1.x);
            // 0(log n)
            set<int>::iterator e = BT.upper_bound(S[EP[i].seg].p2.x);
            // b と e の距離(点の数)を加算 0(k)
            cnt += distance(b, e);
        }
    }
    return cnt;
}


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

int main(void)
{
    int n;
    cin >> n;
    
    vector<Segment> s;
    
    double x1, y1, x2, y2;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        Point p1 = Point(x1, y1);
        Point p2 = Point(x2, y2);
        s.push_back(Segment(p1, p2));
    }

    int cnt = manhattanIntersection(s);

    cout << cnt << endl;

    return 0;
}
