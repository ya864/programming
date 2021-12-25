#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
using namespace std;
map<string, int> dict;

void insert(string t)
{
    dict[t] += 1;
}

void find(string t)
{
    map<string, int>::iterator index_t = dict.find(t);
    if (index_t != dict.end())
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}

int main(void)
{
    int n;

    cin >> n;

    string s, t;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s[0] == 'i') 
        {
            cin >> t;
            insert(t);
        }
        else
        {
            cin >> t;
            find(t);
        }
    }
}
