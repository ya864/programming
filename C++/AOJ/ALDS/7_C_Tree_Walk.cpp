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

struct Node
{
    int parent, left, right;
};
Node T[MAX];
int n, D[MAX], H[MAX];

// 先行順巡回
void preParse(int u)
{
    if (u == NIL) return;
    cout << " " << u;
    preParse(T[u].left);
    preParse(T[u].right);
}

// 中間順巡回
void inParse(int u)
{
    if (u == NIL) return;
    inParse(T[u].left);
    cout << " " << u;
    inParse(T[u].right);
}

// 後行順巡回
void postParse(int u)
{
    if (u == NIL) return;
    postParse(T[u].left);
    postParse(T[u].right);
    cout << " " << u;
}

int main(void)
{
    int v, l, r, root = 0;
    cin >> n;

    for (int i = 0; i < n; i++) T[i].parent = NIL;

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &v, &l, &r);
        T[v].left = l;
        T[v].right = r;
        if (l != NIL) T[l].parent = v;
        if (r != NIL) T[r].parent = v;
    }

    for (int i = 0; i < n; i++){
        if (T[i].parent == NIL) root = i;
    } 

    printf("Preorder\n");
    preParse(root);
    cout << endl;
    printf("Inorder\n");
    inParse(root);
    cout << endl;
    printf("Postorder\n");
    postParse(root);
    cout << endl;

    return 0;
}
