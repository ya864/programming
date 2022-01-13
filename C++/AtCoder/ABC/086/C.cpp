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
#define MAX 100000
#define INF (1 << 30)

int main(void)
{
    int N;
    cin >> N;
    bool can = true;
    
    int dist = 0, dt = 0, t = 0, x, y;
    for (int i = 0; i < N; i++) {
        cin >> t >> x >> y;
        dt = t - dt;
        dist = abs(x + y - dist);
        if (dt < dist) can = false;
        if (dist % 2 != dt % 2) can = false;
    }

    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}