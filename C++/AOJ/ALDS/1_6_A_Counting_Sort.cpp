#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long llong;
#define MAX 2000001
#define VMAX 10000

int main(void)
{
    int n;
    cin >> n;
    
    int A[n + 1], B[n + 1];
    int C[VMAX + 1];
    
    for (int i = 0; i < VMAX + 1; i++)
    {
        C[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> A[i+1];
        C[A[i + 1]]++;
    }
    
    for (int i = 1; i < VMAX + 1; i++)
    {
        C[i] = C[i] + C[i - 1];
    }

    for (int j = 1; j < n + 1; j++)
    {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (i > 1) 
        {
            cout << " ";
        }
        cout << B[i];
    }
    cout << endl;

    return 0;
}
