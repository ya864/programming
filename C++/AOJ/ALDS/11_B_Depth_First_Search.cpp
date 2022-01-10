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
vector<int> t_start;
vector<int> t_end;
vector<bool> visited;
int t;

void dfs(int index)
{
    if (visited[index]) return;
    visited[index] = true;
    t++;
    t_start[index] = t;

    for (int i = 0; i < A[index].size(); i++)
    {
        dfs(A[index][i]);
    }
    
    t++;
    t_end[index] = t;
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
        t_start.push_back(0);
        t_end.push_back(0);
        visited.push_back(false);
        cin >> u >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> v;
            A[u - 1].push_back(v - 1);
        }
    }
    
    t = 0;
    for (int i = 0; i < n; i++)
    {
        dfs(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " " << t_start[i] << " " << t_end[i] << endl;
    }

    return 0;
}
