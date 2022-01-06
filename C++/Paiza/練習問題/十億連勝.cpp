#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
typedef long long llong;
#define MAX 100000
#define NIL -1
#define INF 1 << 30

int mod = pow(10, 9);
map<pair<llong, bool>, llong> states;
map<pair<llong, bool>, llong> new_states;

void push(pair<llong, bool> key, llong val)
{
    new_states[key] += val;
}

int main(void)
{
    int N, X;
    cin >> N >> X;

    vector<int> A;
    for (int i = 0; i < N; i++)
    {
        int l;
        cin >> l;
        A.push_back(l);
    }

    states[make_pair(0, false)] = 1;

    llong wins, comb;
    bool cond;

    for (int i = 0; i < N; i++)
    {
        new_states.clear();
        for (auto it = states.begin(); it != states.end(); it++)
        {
            wins = it->first.first;
            cond = it->first.second;
            comb = it->second;
            if (wins + A[i] <= X)
            {
                // A[i] 全てに勝つ場合
                push(make_pair(wins + A[i], cond), comb);

                // A[i] のどこかで負ける場合
                push(make_pair(0, cond), comb * A[i]);
            }
            else
            {
                // X 連勝ちょうどで負ける場合
                push(make_pair(0, true), comb);

                // X 連勝未満で負ける場合
                push(make_pair(0, cond), comb * (X - wins));
            }
        }
        // 下 9 桁のみにする
        for (auto it = new_states.begin(); it != new_states.end(); it++)
        {
            if (it->second > mod)
            {
                new_states[it->first] = it->second % mod;
            }
        }
        states = new_states;
    }

    // cond が真か wins が X になっているものの総和を出力
    llong ans = 0;
    for (auto it = states.begin(); it != states.end(); it++)
    {
        wins = it->first.first;
        cond = it->first.second;
        comb = it->second;
        if (cond || wins == X)
        {
            ans += comb;
        }
    }

    cout << ans % mod << endl;
    return 0;
}
