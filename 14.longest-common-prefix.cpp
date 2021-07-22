/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

class Trie
{
private:
    bool isTerminal;
    map<char, Trie *> nodes;

public:
    Trie() { isTerminal = false; };
    ~Trie(){};
    void insert(string word)
    {
        Trie *temp = this;
        for (auto &ch : word)
        {
            if (temp->nodes.find(ch) == temp->nodes.end())
                temp->nodes[ch] = new Trie();
            temp = temp->nodes[ch];
        }
        temp->isTerminal = true;
    }
    string LongestCommonPrefix()
    {
        Trie *temp = this;
        string ans = "";
        while ((temp->nodes.size() == 1) and not temp->isTerminal)
        {
            ans.push_back(temp->nodes.begin()->first);
            temp = temp->nodes[temp->nodes.begin()->first];
        }
        return ans;
    }
};

class Solution
{

public:
    string longestCommonPrefix(vector<string> &strs)
    {
        Trie trie;
        for (auto &word : strs)
            trie.insert(word);
        return trie.LongestCommonPrefix();
    }
};
// @lc code=end
