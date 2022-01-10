#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
    int n, q;
    int S[10000];
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }

    cin >> q;
    int ans = 0;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        for (int j = 0; j < n; j++)
        {
            if (S[j] == t)
            {
                ans += 1;
            }
        }
    }

    cout << ans << endl;
}
