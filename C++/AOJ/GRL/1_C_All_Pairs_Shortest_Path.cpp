#include <algorithm>
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
#define MAX 100
#define NIL -1

int n;
static const llong INF = 1LL<<32;
llong d[MAX][MAX];

void floyd()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (d[i][k] == INF)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (d[k][j] == INF)
                    continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(void)
{
    int e, u, v, c;
    cin >> n >> e;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
        {
            d[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < e; i++) {
        cin >> u >> v >> c;
        d[u][v] = c;
    }

    floyd();

    bool negative = false;
    for (int i = 0; i < n; i++) if (d[i][i] < 0) negative = true;

    if (negative) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) cout << " ";
                if (d[i][j] == INF) cout << "INF";
                else cout << d[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
