#include <algorithm>
#include <cassert>
#include <cmath>
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
typedef unsigned long long llong;
#define MAX 1000
#define INF (1 << 30)

ullong A = 9999973, B = 950527;

int H, W;
char T[1005][1005];
ullong t[1005][1005];
ullong t2[1005][1005];
int h, w;
char U[1005][1005];

int main()
{
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; i++)
        scanf("%s", T[i]);

    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++)
        scanf("%s", U[i]);

    ullong target = 0;
    for (int i = 0; i < h; i++)
    {
        ullong key = 0;
        for (int j = 0; j < w; j++)
        {
            key = key * B + U[i][j];
        }
        target = target * A + key;
    }

    ullong C = 1;
    for (int i = 0; i < w; i++)
        C *= B;

    for (int i = 0; i < H; i++)
    {
        ullong key = 0;
        for (int j = 0; j < W; j++)
        {
            key = key * B + T[i][j];
            if (j - w >= 0)
                key -= T[i][j - w] * C;
            t[i][j] = key;
            t2[i][j] = t[i][j];
        }
    }

    C = 1;
    for (int i = 0; i < h; i++)
        C *= A;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i)
                t[i][j] += t[i - 1][j] * A;
            if (i - h >= 0)
                t[i][j] -= t2[i - h][j] * C;
            if (t[i][j] == target)
            {
                if (i - h + 1 >= 0 && j - w + 1 >= 0)
                    printf("%d %d\n", i - h + 1, j - w + 1);
            }
        }
    }

    return 0;
}