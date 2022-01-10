#include <iostream>
#include <algorithm>
using namespace std;

struct Card
{
    char suit;
    int value;
};

void trace(Card A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i < N - 1)
        {
            cout << A[i].suit << A[i].value << " ";
        }
        else
        {
            cout << A[i].suit << A[i].value << endl;
        }
    }
}

void bubbleSort(Card A[], int N)
{
    int i = 0;
    int j;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (j = N - 1; j > i; j--)
        {
            if (A[j].value < A[j - 1].value)
            {
                swap(A[j], A[j - 1]);
                flag = true;
            }
        }
        i++;
    }
}

void selectionSort(Card A[], int N)
{
    int minj;
    for (int i = 0; i < N - 1; i++)
    {
        minj = i;
        for (int j = i; j < N; j++)
        {
            if (A[j].value < A[minj].value)
            {
                minj = j;
            }
        }
        if (i != minj)
        {
            swap(A[i], A[minj]);
        }
    }
}

bool isStable(Card A[], Card B[], int N)
{
    for (int i = 0; i < N; i++)
    {
        if (A[i].suit != B[i].suit)
            return false;
    }
    return true;
}

int main(void)
{
    int N;
    cin >> N;

    Card A[N];
    Card B[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i].suit >> A[i].value;
        B[i] = A[i];
    }

    bubbleSort(A, N);
    trace(A, N);
    cout << "Stable" << endl;
    selectionSort(B, N);
    trace(B, N);
    if (isStable(A, B, N))
    {
        cout << "Stable" << endl;
    }
    else
    {
        cout << "Not stable" << endl;
    }
    return 0;
}
