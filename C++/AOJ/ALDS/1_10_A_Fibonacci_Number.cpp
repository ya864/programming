#include <algorithm>
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
#define MAX 2000000
#define INF (1 << 30)

int main(void)
{
    llong A[100];
    int n;

    cin >> n;

    A[0] = 1;
    A[1] = 1;

    if(n < 2) {
        cout << 1 << endl;
    }
    else {
        for (int i = 2; i <= n; i++)
        {
            A[i] = A[i - 1] + A[i - 2];
        }
        cout << A[n] << endl;
    }

    return 0;
}
