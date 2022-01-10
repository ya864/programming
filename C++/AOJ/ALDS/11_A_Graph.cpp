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
    int n;
    cin >> n;

    int A[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int u, k, v;
        cin >> u >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> v;
            A[u - 1][v - 1] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0) cout << " ";
            cout << A[i][j];
        }
        cout << endl;
    }

    return 0;
}
