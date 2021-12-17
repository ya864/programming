#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
#define LEN 100005

int n, q;

struct proc
{
    string name;
    int time;
};

proc Q[LEN];

int head, tail;

void enqueue(proc p)
{
    Q[tail] = p;
    tail = (tail + 1) % LEN;
}

proc dequeue()
{
    proc p = Q[head];
    head = (head + 1) % LEN;
    return p;
}

int main(void)
{
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> Q[i].name >> Q[i].time;
    }

    int elaps = 0, c;
    proc p;

    head = 0;
    tail = n;

    for (int i = 0 ; i < n ; i++)
    {
        cout << Q[i].name << endl;
    }

    while (head != tail) {
        p = dequeue();
        c = min(q, p.time);
        p.time -= c;
        elaps += c;
        if (p.time > 0) 
        {
            enqueue(p);
        }
        else
        {
            cout << p.name << " " << elaps << endl;
        }
    }
    
    return 0; 
}
