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
    vector<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'B') {
            if (!st.empty()) {
                st.pop_back();
            }
        }
        else {
            st.push_back(s[i]);
        }
    }

    for (int i = 0; i < st.size(); i++){
        cout << st[i];
    };
    cout << endl;

    return 0;
}