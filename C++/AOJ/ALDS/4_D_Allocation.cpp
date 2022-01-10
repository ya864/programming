#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
using namespace std;
#define MAX 100000
typedef long long llong;
vector<int> T;
int n,k;

// 最大積載量Pの k 台のトラックで何個の荷物を積めるか？
bool check(llong P)
{
    int i = 0;
    for (int j = 0; j < k; j++)
    {
        llong s = 0;
        while (s + T[i] <= P)
        {
            s += T[i];
            i += 1;
            if (i == n)
            {
                return true;
            }
        }
    }
    return false;
}

int solve()
{
    llong l = 0;
    // あり得る最大のトラック数と重量の積がPの理論最大値
    llong r = MAX * 10000;
    llong mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return r;
}

int main(void)
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        T.push_back(a);
    }
    llong ans = solve();
    cout << ans << endl;
}
