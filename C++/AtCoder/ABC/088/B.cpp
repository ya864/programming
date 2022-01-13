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

    vector<int> A;
    for (int i = 0; i < N; i++) {
        int a = 0;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end(), greater<int>());

    int alice = 0, bob = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) alice += A[i];
        else bob += A[i];
    }
    
    cout << alice - bob << endl;

    return 0;
}