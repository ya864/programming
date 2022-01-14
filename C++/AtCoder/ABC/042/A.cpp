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
    int a;
    int five = 0, seven = 0;
    for (int i = 0; i < 3; i++) {
        cin >> a;
        if (a == 5) {
            five++;
        }
        if (a == 7) {
            seven++;
        }
    }

    if (five == 2 && seven == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}