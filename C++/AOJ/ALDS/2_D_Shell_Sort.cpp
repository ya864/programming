#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long cnt;
vector<int> G;
void trace(vector<int> A)
{
    int p;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (i > 0)
        {
            cout << A[i] << " ";
        }
        else
        {
            cout << A[i] << endl;
        }
    }
}

void selectionSort(int A[], int N, int g)
{
    int minj;
    for (int i = 0; i < N - 1; i++)
    {
        minj = i;
        for (int j = i; j < N; j += g)
        {
            if (A[j] < A[minj])
            {
                minj = j;
            }
        }
        if (i != minj)
        {
            swap(A[i], A[minj]);
            cnt++;
        }
    }
}

void shellSort(int A[], int N)
{
    for (int h = 1; h < N; h = h * 3 + 1)
    {
        G.push_back(h);
    }
    for (int i = G.size() - 1; i >= 0; i--)
    {
        selectionSort(A, N, G[i]);
    }
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

    shellSort(A, N);
    cout << G.size() << endl;
    trace(G);
    cout << cnt << endl;
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << endl;
    }
    
    return 0;
}
