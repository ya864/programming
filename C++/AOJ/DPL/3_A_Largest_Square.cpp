#include <algorithm>
#include <bits/stdc++.h>
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
#define MAX 1400
#define EPS (1e-10)
#define DIAGONAL 1
#define TOP 0

int dp[MAX][MAX], G[MAX][MAX];

int getLargestSquare(int H, int W)
{
    int maxWidth = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            dp[i][j] = (G[i][j] + 1) % 2;
            maxWidth |= dp[i][j];
        }
    }

    for (int i = 1; i < H; i++) {
        for (int j = 1; j < W; j++) {
            if (G[i][j]) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                maxWidth = max(maxWidth, dp[i][j]);
            }
        }
    }

    return maxWidth * maxWidth;
}

int main(void)
{
    int H, W;
    cin >> H >> W;

    int a;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a;
            G[i][j] = a;
        }
    }

    cout << getLargestSquare(H, W) << endl;

    return 0;
}
