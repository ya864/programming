#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
typedef long long llong;
#define ALPHABET_SIZE 26

struct TrieNode
{
    int value = 0;
    vector<int> children;
    
    TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; i++){
            this->children.push_back(-1);
        }
    }
};

struct Trie
{
    TrieNode root;
    vector<TrieNode> nodes;
    
    Trie() {
        nodes.push_back(root);
    }
    
    int add_node()
    {
        TrieNode new_node;
        nodes.push_back(new_node);
        return nodes.size() - 1;
    }

    int search(string s)
    {
        int node_index = 0;
        for (int i = 0 ; i < s.length(); i++)
        {
            int char_num = s[i] - 'a';
            node_index = nodes[node_index].children[char_num];
            if (node_index == -1) break;
        }
        return node_index;
    }
    
    int calc(int node_index)
    {
        int val = 0;
        stack<int> index_array;
        index_array.push(node_index);
        
        int next_index;
        while (index_array.size() > 0)
        {
            next_index = index_array.top();
            index_array.pop();
            val += nodes[next_index].value;
            for (int i = 0; i < ALPHABET_SIZE; i++)
            {
                if (nodes[next_index].children[i] != -1)
                {
                    index_array.push(nodes[next_index].children[i]);
                }
            }
        }
        
        return val;   
    }

    void insert(string s, int v, int char_index, int node_index)
    {
        int char_num = s[char_index] - 'a';
        int next_node_index = nodes[node_index].children[char_num];
        if (next_node_index == -1) {
            next_node_index = add_node();
            nodes[node_index].children[char_num] = next_node_index;
        }
        if (char_index == s.length() -1)
        {
            nodes[next_node_index].value += v;
        }
        else
        {
            insert(s, v, char_index+1, next_node_index);
        }
    }

};

Trie trie;
int n, m;

int main(void)
{
    cin >> n >> m;
    string s;
    int p;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> p;
        trie.insert(s, p, 0, 0);
    }
    
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        int node_index = trie.search(s);
        if (node_index == -1) 
        {
            cout << "0" << endl;
        }
        else
        {
            int val = trie.calc(node_index);
            cout << val << endl;
        }
    }
    
    return 0;
}
