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
    int N, Y;
    cin >> N >> Y;

    int A = -1, B = -1, C = -1;
    for (int a = 0; a <= N; a++){
        for (int b = 0; a + b <= N; b++) {
            int c = N - a - b;
            int num = a * 10000 + b * 5000 + c * 1000;
            if (num == Y && a + b + c == N) {
                A = a;
                B = b;
                C = c;
            }
        }
    }

    cout << A << " " << B << " " << C << endl;

    return 0;
}