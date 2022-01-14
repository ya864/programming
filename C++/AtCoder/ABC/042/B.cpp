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
    int N, L;
    cin >> N >> L;
    
    vector<string> A;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        A.push_back(s);
    }
    sort(A.begin(), A.end());

    string ans;
    for (int i = 0; i < N; i++) {
        ans += A[i];
    }

    cout << ans << endl;
    return 0;
}