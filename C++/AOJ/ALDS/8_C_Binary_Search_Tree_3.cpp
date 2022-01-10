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

Node *treeSuccessor(Node *x)
{
    if (x->right != NIL) return treeMinimum(x->right);
    Node *y = x->parent;
    while (y != NIL && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

void treeDelete(Node *z)
{
    Node *y; // 削除の対象
    Node *x; // y の子

    // 削除する接点を求める
    if (z->left == NIL || z->right == NIL) y = z;
    else y = treeSuccessor(z);

    // y の子 x を決める
    if (y->left != NIL) {
        x = y->left;
    } else {
        x = y->right;
    }

    if (x != NIL) {
        x->parent = y->parent;
    }

    if (y->parent == NIL) {
        root = x;
    } else {
        if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
    }

    if (y != z) {
        z->key = y->key;
    }

    free(y);
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
        else if (com == "delete")
        {
            scanf("%d", &x);
            treeDelete(find(root, x));
        }
    }

    return 0;
}
