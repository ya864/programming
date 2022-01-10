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

static const int NMAX = 10000;

llong GCD(llong a, llong b) {
    if (a < b) swap(a, b);

    while (b > 0) {
        llong r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main(void)
{
    llong x, y;
    cin >> x >> y;

    llong ans = GCD(x, y);

    cout << ans << endl;

    return 0;
}
