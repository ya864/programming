#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long llong;
#define MAX 10000
#define NIL -1

int n, pos;
vector<int> pre, in, post;

void rec(int l, int r) 
{
    if (l >= r) return;
    int root = pre[pos++];
    int m = distance(in.begin(), find(in.begin(), in.end(), root));
    rec(l, m);
    rec(m + 1, r);
    post.push_back(root);
}

void solve() {
    pos = 0;
    rec(0, pre.size());
    for (int i = 0; i < n; i++)
    {
        if (i > 0) cout << " ";
        cout << post[i];
    }
    cout << endl;
}

int main(void)
{
    int k;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        pre.push_back(k);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        in.push_back(k);
    }
    solve();

    return 0;
}
