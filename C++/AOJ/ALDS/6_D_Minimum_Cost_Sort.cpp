#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long llong;
#define MAX 1000
#define VMAX 10000

int n, A[MAX], s;
int B[MAX], T[VMAX + 1];

int solve() 
{
    int ans = 0;

    bool V[MAX];
    for (int i = 0; i< n; i++)
    {
        B[i] = A[i];
        V[i] = false;
    }
    sort(B, B + n);
    for (int i = 0; i < n; i++) T[B[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (V[i]) continue;
        int cur = i;
        int S = 0;
        int m = VMAX;
        int an = 0;
        while (true) 
        {
            V[cur] = true;
            an++;
            int v = A[cur];
            m = min(m, v);
            S += v;
            cur = T[v];
            if (V[cur]) break;
        }
        ans += min(S +(an - 2) * m, m + S +(an + 1) * s);
    }
    return ans;
}

int main(void)
{
    cin >> n;
    s = VMAX;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        s = min(s, A[i]);
    }
    int ans = solve();
    cout << ans << endl;

    return 0;
}
