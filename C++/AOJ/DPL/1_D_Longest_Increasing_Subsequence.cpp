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


int n, A[MAX+1], L[MAX+1];

int lis() {
    L[0] = A[0];
    int length = 1;

    for (int i = 1; i < n; i++) {
        if (L[length - 1] < A[i]) {
            L[length++] = A[i];
        } else {
            *lower_bound(L, L + length, A[i]) = A[i];
        }
    }

    return length;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << lis() << endl;

    return 0;
}
