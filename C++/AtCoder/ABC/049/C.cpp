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
#include <regex>
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
    string T1 = "resare";

    string T2 = "esare";
    string T3 = "remaerd";
    string T4 = "maerd";
    string S;
    cin >> S;

    string SR(S.rbegin(), S.rend());
    SR = regex_replace(SR, regex(T1), "");
    SR = regex_replace(SR, regex(T2), "");
    SR = regex_replace(SR, regex(T3), "");
    SR = regex_replace(SR, regex(T4), "");

    if (SR.length() == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}