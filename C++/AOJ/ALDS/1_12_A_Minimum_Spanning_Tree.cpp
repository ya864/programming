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
int n;

int prim()
{
    // 頂点のマークを保持する配列
    bool marked[n];
    for (int i = 0; i < n; i++) marked[i] = false;
    // マークされている頂点の数
    int marked_count = 0;
    
    // 優先度付きキュー 小さい順に取り出せるようにする
    priority_queue<pi, vector<pi>, greater<pi>> que;
    
    // 重みの合計
    int sum = 0;
    
    marked[0] = true;
    marked_count += 1;
    
    pair<int, int> pr;
    
    for (int i = 0; i < A[0].size(); i++)
    {
        pr = A[0][i];
        que.push(pr);
    }
    int c,i;
    while (marked_count < n) {
        pr = que.top();
        que.pop();
        c = pr.first;
        i = pr.second;

        if (marked[i]) continue;
        
        marked[i] = true;
        marked_count += 1;

        sum += c;
        for (int j = 0; j < A[i].size(); j++)
        {
            pr = A[i][j];
            if (marked[pr.second]) continue;
            que.push(pr);
        }
    }
    
    return sum;
}

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        A.push_back(vector<pair<int, int>>());
    }

    int c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            if (c == -1) continue;
            A[i].push_back(make_pair(c, j));
        }
    }

    int ans = prim();
    cout << ans << endl;
    
    return 0;
}
