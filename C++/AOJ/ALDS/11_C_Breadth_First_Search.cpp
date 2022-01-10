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
#define MAX 2000000
#define INF (1 << 30)

vector<vector<int>> A;
vector<int> dist_from_A;
vector<bool> visited;

void bfs(int start_index)
{
    queue<pair<int, int>> que;
    que.push(make_pair(start_index, 0));

    pair<int, int> now;
    while (que.size() > 0)
    {
        now = que.front();
        que.pop();
        if (visited[now.first]) continue;
        visited[now.first] = true;
        dist_from_A[now.first] = min(dist_from_A[now.first], now.second);
        for (int i = 0; i < A[now.first].size(); i++){
            que.push(make_pair(A[now.first][i], now.second + 1));
        }
    }

    return;
}

int main(void)
{
    int n;
    cin >> n;
    int u, k, v;
    
    for (int i = 0; i < n; i++)
    {
        A.push_back(vector<int>());
        dist_from_A.push_back(INF);
        visited.push_back(false);
        cin >> u >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> v;
            A[u - 1].push_back(v - 1);
        }
    }
    
    bfs(0);
    
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " ";
        if (dist_from_A[i] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dist_from_A[i] << endl;
        }
        
    }

    return 0;
}
