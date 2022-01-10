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

struct Rectangle
{
    int height;
    int pos;
};

int getLargestRectangle(int size, int buffer[]) {
    stack<Rectangle> S;
    int maxv = 0;
    buffer[size] = 0;

    for (int i = 0; i <= size; i++) {
        Rectangle rect;
        rect.height = buffer[i];
        rect.pos = i;
        if (S.empty()) {
            S.push(rect);
        } else {
            if (S.top().height < rect.height ) {
                S.push(rect);
            } else if (S.top().height > rect.height) {
                int target = i;
                while (!S.empty() && S.top().height >= rect.height) {
                    Rectangle pre = S.top();
                    S.pop();
                    int area = pre.height * (i - pre.pos);
                    maxv = max(maxv, area);
                    target = pre.pos;
                }
                rect.pos = target;
                S.push(rect);
            }
        }
    }
    return maxv;
}

int H, W;
int buffer[MAX][MAX];
int T[MAX][MAX];

int solve() {
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H; i++) {
            if (buffer[i][j]) {
                T[i][j] = 0;
            } else {
                T[i][j] = (i > 0) ? T[i - 1][j] + 1 : 1;
            } 
        }
    }

    int maxv = 0;
    for (int i = 0; i < H; i++) {
        maxv = max(maxv, getLargestRectangle(W, T[i]));
    }

    return maxv;
}


int main(void)
{
    cin >> H >> W;

    int a;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> a;
            buffer[i][j] = a;
        }
    }

    cout << solve() << endl;

    return 0;
}
