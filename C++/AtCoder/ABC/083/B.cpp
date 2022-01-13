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
    int N, A, B;
    cin >> N >> A >> B;
    
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        string s = to_string(i);
        int num = 0;
        for (int j = 0; j < s.length(); j++) {
            num += s[j] - '0';
        }
        if (A <= num && num <= B) ans += i;
    }
    cout << ans << endl;

    return 0;
}