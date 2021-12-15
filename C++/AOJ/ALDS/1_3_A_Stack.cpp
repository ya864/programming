#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

int top;
int S[10000];

void push(int x)
{
    // topを加算してからtopに追加
    top++;
    S[top] = x;
}

int pop()
{
    top--;
    return S[top + 1];
}

int main(void)
{
    int a, b;
    top = 0;
    string l;
    while (cin >> l)
    {
        if (l == "+")
        {
            a = pop();
            b = pop();
            push(a + b);
        }
        else if (l == "-")
        {
            b = pop();
            a = pop();
            push(a - b);
        }
        else if (l == "*")
        {
            a = pop();
            b = pop();
            push(a * b);
        }
        else
        {
            push(stoi(l));
        }
    }

    cout << pop() << endl;

    return 0;
}
