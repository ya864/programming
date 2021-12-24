#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> list;
    vector<int> cpy_list;
    list.push_back(0);
    for (int i = 1; i < N; i++)
    {   
        cpy_list.clear();
        for (int i = 0; i < list.size(); i++) 
        {
            cpy_list.push_back(list[i]);
        }
        list.clear();
        list.push_back(0);
        for (int i = 0; i < cpy_list.size(); i++)
        {
            list.push_back(cpy_list[i]);
            if (i % 2 == 0)
            {
                list.push_back(1);
            }
            else
            {
                list.push_back(0);
            }
        }
    }

    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i];
    }
    cout << endl;
    return 0;
}
