#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <list>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
typedef long long llong;
#define MAX 100000
#define NIL -1

vector<int> G[MAX];
list<int> out;
bool V[MAX];
int N;

void dfs(int u) {
    V[u] = true;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (!V[v]) dfs(v);
    }
    out.push_front(u);
}

int main(void)
{
    int s, t, M;

    cin >> N >> M;

    for (int i = 0; i < N; i++) V[i] = false;

    for (int i = 0; i < M; i++) {
        cin >> s >> t;
        G[s].push_back(t);
    }

    for (int i = 0; i < N; i++)
    {
        if (!V[i]) dfs(i);
    }

    for (list<int>::iterator it = out.begin(); it != out.end(); it++){
        cout << *it << endl;
    }

    return 0;
}
