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
#define N 8
#define FREE -1
#define NOT_FREE 1

int row[N], col[N], dpos[2 * N - 1], dneg[2 * N - 1];
bool X[N][N];

void initialize()
{
    for (int i = 0; i < N; i++)
    {
        row[i] = FREE;
        col[i] = FREE;
    }
    for (int i = 0; i < N * 2 - 1; i++)
    {
        dpos[i] = FREE;
        dneg[i] = FREE;
    }
}

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (X[i][j]){
                if (row[i] != j) return;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << (row[i] == j ? "Q" : ".");
        }
        cout << endl;
    }
}

void recursive(int i)
{
    if (i == N)
    {
        // クイーンの配置に成功
        printBoard();
    }

    for (int j = 0; j < N; j++)
    {
        // (i,j)が他のクイーンに襲撃されている場合は無視
        if (NOT_FREE == col[j] ||
            NOT_FREE == dpos[i + j] ||
            NOT_FREE == dneg[i - j + N - 1])
            continue;

        // (i, j)にクイーンを配置する
        row[i] = j;
        col[j] = dpos[i + j] = dneg[i - j + N - 1] = NOT_FREE;
        // 次の行を試す
        recursive(i + 1);
        // (i, j)に配置されているクイーンを取り除く
        row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = FREE;
    }
    // クイーンの配置に失敗
}

int main(void)
{
    initialize();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            X[i][j] = false;
        }
    }

    int k;
    cin >> k;
    int r, c;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        X[r][c] = true;
    }

    recursive(0);
 
    return 0;
}
