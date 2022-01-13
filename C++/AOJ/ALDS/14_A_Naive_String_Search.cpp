#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <cmath>
#include <cassert>
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
    
    string p;
    cin >> p;
    

    for (int i = 0; i < s.length() - p.length() + 1; i++) {
        if (s.length() < p.length()) break;
        bool flag = true;
        for (int j = 0; j < p.length(); j++) {
            if (s[i + j] != p[j]) {
                flag = false;
                int index = i;
                while (index > s.length()) {
                    if (s[index] != p[0]) index++;
                }
                break;
            }
        }
        if (flag) cout << i << endl;
    }

    return 0;
}