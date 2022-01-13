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
    int N;
    cin >> N;

    map<int, int> dic;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        dic[a] = 1;
    }

    cout << dic.size() << endl;

    return 0;
}