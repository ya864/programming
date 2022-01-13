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

    int A[n];
	bool flag = true;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
      	if (A[i] % 2 == 1) flag = false;
    }

    int cnt = 0;

    while (flag)
    {
        for (int i = 0; i < n; i++) {
            A[i] /= 2;
            if (A[i] % 2 == 1) {
         		flag = false;
	            break;
            }
        }
       	cnt++;
    }

    cout << cnt << endl;
    return 0;
}