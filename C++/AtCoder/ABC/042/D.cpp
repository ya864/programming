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
typedef unsigned long long ullong;
#define MAX 200100 // MAXH + MAXW
#define INF (1 << 30)

const int MOD = 1e9 + 7;
llong fact[MAX];
llong n, m, a, b;

llong power(llong x, llong k)
{
	llong ans=1;
	while(k)
	{
		if(k&1) ans*=x,ans%=MOD;
		x*=x;x%=MOD;
		k>>=1;
	}
	return ans;
}
llong Comb(llong x, llong y) {
    return fact[x] * power(fact[y], MOD -2) % MOD * power(fact[x - y], MOD -2) % MOD;
}

llong Count(llong ax, llong ay, llong bx, llong by){
    return Comb(bx - ax + by - ay, bx - ax);
}

int main(void)
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= MAX-100; i++) fact[i] = fact[i - 1] * i % MOD;
    cin >> n >> m >> a >> b;

    int ans = 0;
    for (int i = 1; i <= n - a; i++) {
        ans += Count(1, 1, i, b) * Count(i, b+1, n, m) % MOD;
        ans %= MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}