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

static const int N = 100;

int main(void)
{
    int n, p[N + 1], m[N + 1][N + 1];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i - 1] >> p[i];
    }

    for (int i = 0; i <= n; i++) m[i][i] = 0;
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = (1 << 21);
            for (int k = i; k <= j - 1; k++)
            {
                m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }

    cout << m[1][n] << endl;

    return 0;
}
