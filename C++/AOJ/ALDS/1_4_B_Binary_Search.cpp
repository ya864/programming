#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
int n, q;
int S[100000];

bool binary_search(int t)
{
    int l = 0;
    int r = n;
    while (l < r)
    {
        int mid = (l + r) / 2;
        
        if (S[mid] == t)
        {
            return true;
        }
        else if (t < S[mid] )
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return false;
}

int main(void)
{
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
        if (binary_search(t))
        {
            ans += 1;
        }
    }

    cout << ans << endl;
}
