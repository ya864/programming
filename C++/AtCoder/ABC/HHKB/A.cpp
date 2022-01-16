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
    string s;
    cin >> s;
    string a = s[0];
    string b = s[1];
    string c = s[2];

    int ans = (int) a+bc * 100 + (int)b+c+a * 10 + (int) c + b+ a;
    cout << ans << endl;
    return 0;
}