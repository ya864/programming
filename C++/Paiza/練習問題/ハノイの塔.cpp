#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

queue<int> _from;
queue<int> _to;

void hanoi(int n, int f, int t, int work)
{
    if (n > 0)
    {
        hanoi(n - 1, f, work, t);
        // 配列に動かした順番を保存していく
        _from.push(f);
        _to.push(t);
        hanoi(n - 1, work, t, f);
    }
}

int main(void)
{
    int N, T;
    cin >> N >> T;

    // ハノイの解決
    hanoi(N, 0, 2, 1);

    vector<vector<int> > sticks(3);
    
    // 一番左の棒にディスクセット
    for (int i = 0 ; i < N ; i++)
    {
        sticks[0].push_back(N - i);        
    }
    
    int a, b, c;
    // 棒を記録した配列通りに移動させる
    for (int i = 0; i < T; i++)
    {
        a = _from.front();
        _from.pop();
        b = _to.front();
        _to.pop();
        c = sticks[a][sticks[a].size() - 1];
        sticks[a].pop_back();
        sticks[b].push_back(c);
    }

    // 棒の状態出力
    for (int i = 0; i < 3; i++)
    {
        if (sticks[i].size() == 0)
        {
            cout << "-" << endl;
        }
        else
        {
            for (int j = 0; j < sticks[i].size(); j++)
            {
                cout << sticks[i][j];
                if (j < sticks[i].size() - 1)
                {
                    cout  << " ";
                }
            }
            cout << endl;
        }
    }
}
