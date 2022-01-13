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
    string T;
    cin >> T;
    
    string P;
    cin >> P;
    
	for (size_t s = T.find(P); s != string::npos; s = T.find(P, s)) {
		printf("%d\n", s++);
	}
    return 0;
}