#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
typedef long long llong;
#define MAX 100000
#define NIL -1
#define INF 1<<30
//static const llong INF = 1LL << 32;

class Edge
{
public:
    int t, w;
    Edge() {}
    Edge(int t, int w) : t(t), w(w) {}
};

vector<Edge> G[MAX];
int n, d[MAX];

bool vis[MAX];
int cnt;

void bfs(int s)
{
    for (int i = 0; i < n; i++)
        d[i] = INF;
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    int u;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for (int i = 0; i < G[u].size(); i++)
        {
            Edge e = G[u][i];
            if (d[e.t] == INF)
            {
                d[e.t] = d[u] + e.w;
                Q.push(e.t);
            }
        }
    }
}

void solve()
{
    // 適当な始点 s から最も遠い接点 tgt を求める
    bfs(0);
    int maxv = 0;
    int tgt = 0;
    for (int i = 0; i < n; i++)
    {
        if (d[i] == INF) continue;
        if (maxv < d[i]) {
            maxv = d[i];
            tgt = i;
        }
    }

    // tgt から最も遠い接点の距離 maxv を求める
    bfs(tgt);
    maxv = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] == INF) continue;
        maxv = max(maxv, d[i]);
    } 

    cout << maxv << endl;
}

int main(void)
{
    int s, t, w;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        cin >> s >> t >> w;

        G[s].push_back(Edge(t, w));
        G[t].push_back(Edge(s, w));
    }

    solve();
    return 0;
}
