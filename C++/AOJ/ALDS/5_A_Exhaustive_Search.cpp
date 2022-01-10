#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
using namespace std;
typedef long long llong;
int n,q,m;
vector<int> A;

bool dfs(int i, int t)
{
    if (m == t) return true;
    if (i >= n) return false;
    bool flg = dfs (i + 1, t + A[i]) || dfs (i + 1, t);
    return flg;
}

int main(void)
{
    cin >> n;

    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        A.push_back(a);
    }

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> m;
        if (dfs(0, 0))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}
