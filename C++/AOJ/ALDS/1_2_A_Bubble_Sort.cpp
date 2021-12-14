#include <iostream>
#include <algorithm>
using namespace std;

void trace(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i < N - 1)
        {
            cout << A[i] << " ";
        }
        else
        {
            cout << A[i] << endl;
        }
    }
}

int bubbleSort(int A[], int N)
{
    // 交換回数記録変数
    int cnt = 0;
    int i = 0;
    int j, tmp;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (j = N - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                tmp = A[j];
                A[j] = A[j - 1];
                A[j-1] = tmp;
                cnt += 1;
                flag = true;
            }
        }
        i++;
    }
    trace(A, N);
    return cnt;
}

int main(void)
{
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int ans = bubbleSort(A, N);
    cout << ans << endl;
    return 0;
}
