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
typedef pair<int, int> pi;

vector<vector<pair<int, int>> > A;
vector<int> dist;
vector<bool> done;
int E, V, T;

void dijkstra()
{
    for (int i = 0; i < V; i++) dist.push_back(-1);
    
    for (int i = 0; i < V; i++) done.push_back(false);
    
    // 始点の距離は0
    dist[0] = 0;
    
   // 優先度付きキュー 小さい順に取り出せるようにする
    priority_queue<pi, vector<pi>, greater<pi>> que;
    
    pair<int, int> pr;
    pr = make_pair(0, 0);
    que.push(pr);
    int c,d,i,j;
    
    while (que.size() > 0)
    {
        pr = que.top();
        que.pop();
        
        d = pr.first;
        i = pr.second;
        
        if (done[i]) continue;
        
        done[i] = true;
        
        for (int u = 0; u < A[i].size(); u++)
        {
            pr = A[i][u];
            
            c = pr.first;
            j = pr.second;
            if (dist[j] == -1 || dist[j] > dist[i] + c)
            {
                dist[j] = dist[i] + c;
                que.push(make_pair(dist[j], j));
            }
        }
    }
}

int main(void)
{
    cin >> E >> V >> T;

    for (int i = 0; i < V; i++)
    {
        A.push_back(vector<pair<int, int>>());
    }

    int u,v,c;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> c;
        A[u].push_back(make_pair(c, v));
        A[v].push_back(make_pair(c, u));
    }
    
    dijkstra();
    
    
    cout << dist[T] << endl;

    return 0;
}
