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

int selectionSort(int A[], int N)
{
    // 交換回数記録変数
    int cnt = 0;
    int minj;
    for (int i = 0; i < N - 1; i++)
    {
        minj = i;
        for (int j = i; j < N; j++) 
        {
            if (A[j] < A[minj])
            {
                minj = j;
            }
        }
        if (i != minj) {
            swap(A[i], A[minj]);
            cnt++;
        }
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

    int ans = selectionSort(A, N);
    cout << ans << endl;
    return 0;
}
