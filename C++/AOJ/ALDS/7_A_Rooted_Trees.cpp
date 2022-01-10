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
#define MAX 100005
#define NIL -1

struct Node
{
    int parent, left, right;
};

Node T[MAX];
int n, D[MAX];

void print(int u)
{
    int i, c;
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << D[u] << ", ";

    if (T[u].parent == NIL) cout << "root, ";
    else if (T[u].left == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";

    i = 0;
    c = T[u].left;
    while (c != NIL) {
        if (i > 0) cout << ", ";
        cout << c;
        c = T[c].right;
        i++;
    }

    cout << "]" << endl;
}

// 再帰的に深さを求める
void rec(int u, int p)
{
    D[u] = p;
    // 右の兄弟に同じ深さを設定
    if (T[u].right != NIL) rec(T[u].right, p); 
    // 最も左の子に自分の深さ+1を設定
    if (T[u].left != NIL) rec(T[u].left, p + 1);
}

int main(void)
{
    int d, v, c, l, r;
    cin >> n;

    for (int i = 0; i < n; i++) T[i].parent = T[i].left = T[i].right = NIL;

    for (int i = 0; i < n; i++)
    {
        cin >> v >> d;
        for (int j = 0; j < d; j++) {
            cin >> c;
            if (j == 0) T[v].left = c;
            else T[l].right = c;
            l = c;
            T[c].parent = v;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (T[i].parent == NIL) r = i;
    }

    rec(r, 0);

    for (int i = 0; i < n; i++) print(i);

    return 0;
}
