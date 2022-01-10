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

struct Node
{
    int key;
    Node *right, *left, *parent;
};

Node *root, *NIL;

void insert(int k)
{
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while (x != NIL)
    {
        y = x;
        if (z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == NIL)
    {
        root = z;
    }
    else
    {
        if (z->key < y->key)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }
    }
}

Node * find(Node *u, int k)
{
    while(u != NIL && k != u->key) {
        if (k < u->key) u = u->left;
        else u = u->right;
    }
    return u;
}


Node *treeMinimum(Node *x)
{
    while (x->left != NIL)
    {
        x = x->left;
    }
    return x;
}

void inorder(Node *u)
{
    if (u == NIL)
        return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}
void preorder(Node *u)
{
    if (u == NIL)
        return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

int main(void)
{
    int n, x;
    string com;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        cin >> com;
        if (com == "insert") {
            scanf("%d", &x);
            insert(x);
        }
        else if (com == "find")
        {
            scanf("%d", &x);
            Node *t = find(root, x);
            if (t != NIL)
            {
                printf("yes");
            }
            else
            {
                printf("no");
            }
            printf("\n");
        }
        else if (com == "print")
        {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }

    return 0;
}
