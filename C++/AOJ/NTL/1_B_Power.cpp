#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
typedef long long llong;
typedef unsigned long long ullong;
#define MAX 100000
#define NIL -1
#define INF 1<<30

static const ullong MOD = 1000000007;

ullong power(ullong x, ullong n) {
    ullong res = 1;
    if (n > 0) {
        res = power(x, n / 2);
        if (n % 2 == 0) res = (res * res) % MOD;
        else res = (((res * res) % MOD) * x) % MOD;
    }
    return res;
}

int main(void)
{
    ullong m, n;
    cin >> m >> n;

    cout << power(m, n) << endl;

    return 0;
}
