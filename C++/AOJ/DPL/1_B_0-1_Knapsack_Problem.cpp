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
#define MAX 100000
#define EPS (1e-10)
#define DIAGONAL 1
#define TOP 0

static const int NMAX = 100;
static const int WMAX = 10000;
static const int INF = (1 << 29);

struct Item {
    int value, weight;
    // Item(int value, int weight) : value(value), weight(weight) {}
};

int N, W;
Item items[NMAX + 1];
int C[NMAX + 1][WMAX + 1];
int G[NMAX + 1][WMAX + 1];

int compute(int &maxValue) {
    for (int w = 0; w <= W; w++) {
        C[0][w] = 0;
        G[0][w] = DIAGONAL;
    }

    for (int i = 1; i <= N; i++) C[i][0] = 0;

    for(int i = 1; i <= N; i++) {
        for(int w = 1; w <= W; w++) {
            C[i][w] = C[i - 1][w];
            G[i][w] = TOP;
            if (items[i].weight > w) continue;
            if (items[i].value + C[i - 1][w - items[i].weight] > C[i - 1][w]) {
                C[i][w] = items[i].value + C[i - 1][w - items[i].weight];
                G[i][w] = DIAGONAL;
            }
        }
    }

    return C[N][W];
}

int main(void)
{
    cin >> N >> W;

    int v, w;
    for (int i = 0; i < N; i++) {
        cin >> v >> w;
        Item it;
        it.value = v;
        it.weight = w;
        items[i+1] = it;
    }

    int ans = compute(W);
    
    cout << ans << endl;
    return 0;
}
