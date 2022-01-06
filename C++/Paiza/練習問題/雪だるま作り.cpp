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
#define MAX 100000
#define NIL -1
#define INF 1 << 30

int main(void)
{
    int N, K;
    cin >> N >> K;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    llong ans = 0;
    int left = 0;
    int right = N - 1;
    sort(A, A+N);
    while (left < right)
    {
        if (A[left] + A[right] >= K)
        {
            ans++;
            left++;
            right--;
        }
        else
        {
            left++;
        }
    }

    cout << ans << endl;

    return 0;
}
