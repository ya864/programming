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
#define MAX 100000
#define INF (1 << 30)

vector<vector<int> > A;
int color[MAX];

void bfs(int start_index, int id)
{
    queue<int> que;
    que.push(start_index);
    
    int visited[100000] = {};

    int now;
    int cnt = 0;
    while (que.size() > 0)
    {
        cnt++;
        now = que.front();
        que.pop();
        color[now] = id;
        if (visited[now] == 1) continue;
        visited[now] = 1;
        for (int i = 0; i < A[now].size(); i++){
            que.push(A[now][i]);
        }
    }
    return;
}

int main(void)
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        A.push_back(vector<int>());
    }

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    int k;
    cin >> k;
    
    int id = 1;
    for (int i = 0; i < n; i++) color[i] = -1;
    for (int u = 0; u < n; u++) {
        if (color[u] == -1) {
            bfs(u, id);
            id++;
        }
    }
    
    int s, t;
    bool flag;
    for (int i = 0; i < k; i++)
    {
        cin >> s >> t;
        if (color[s] == color[t]) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
