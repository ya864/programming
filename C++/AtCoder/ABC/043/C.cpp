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
    int n;
    cin >> n;
    vector<int> A;
    int a;

    int mina = 99999999;
    int maxa = -99999999;
    for (int i = 0; i < n; i++) {
        cin >> a;
        mina = min(mina, a);
        maxa = max(maxa, a);
        A.push_back(a);
    }
    int ans = 99999999;
    int cost = 0;
    for (int i = mina; i <= maxa; i++) {
        cost = 0;
        for (int j = 0; j < A.size(); j++) {
            cost += pow(i - A[j], 2);
        }
        
        ans = min(ans, cost);
    }

    cout << ans << endl;
    
    return 0;
}