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
#define MAX 10000
#define INF (1 << 30)

bool no[10];

bool check(int a)
{
    // 各桁の数字のチェック
    while (a)
    {
        if (no[n % 10])
            return false;
        n /= 10;
    }
    return true;
}

int main(void)
{
    int N, K;
    cin >> N >> K;
    int d;
    while (K--) {
        cin >> d;
        no[d] = true;
    }
    while (!check(N)) {
        N++;
    }

    cout << N << endl;
    return 0;
}