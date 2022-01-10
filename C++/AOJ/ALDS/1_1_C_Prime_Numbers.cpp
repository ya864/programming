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

bool isPrime(llong a) {
    if (a == 2) return true;
    if (a < 2 || a % 2 == 0) return false;

    llong i = 3;
    while i < sqrt(a) {
        if (a % i == 0) {
            return true;
        }
        i += 2;
    }
    return true;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    int C[MMAX + 1];
    int T[NMAX + 1];

    for (int i = 1; i <= m; i++) {
        cin >> C[i];
    }

    for (int i = 0; i <= NMAX; i++) T[i] = INF;
    T[0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j + C[i] <= n; j++) {
            T[j + C[i]] = min(T[j + C[i]], T[j] + 1);
        }
    }
    
    cout << T[n] << endl;

    return 0;
}
