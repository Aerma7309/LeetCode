/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
#include <bits/stdc++.h>
// @lc code=start
class Solution
{
    class Trie
    {
        bool isTerminal;
        map<char, Trie *> h;

    public:
        /** Initialize your data structure here. */
        Trie()
        {
            isTerminal = false;
        }

        /** Inserts a word into the trie. */
        void insert(string word)
        {
            Trie *curr = this;
            for (auto &i : word)
            {
                if (curr->h.find(i) != curr->h.end())
                    curr = curr->h[i];
                else
                {
                    Trie *newNode = new Trie();
                    curr->h[i] = newNode;
                    curr = newNode;
                }
            }
            curr->isTerminal = true;
        }

        /** Returns if the word is in the trie. */
        bool search(string word)
        {
            Trie *curr = this;
            for (auto &i : word)
            {
                if (curr->h.find(i) != curr->h.end())
                    curr = curr->h[i];
                else
                    return false;
            }
            return curr->isTerminal;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix)
        {
            Trie *curr = this;
            for (auto &i : prefix)
            {
                if (curr->h.find(i) != curr->h.end())
                    curr = curr->h[i];
                else
                    return false;
            }
            return true;
        }

        string longestPrefix()
        {
            Trie *curr = this;
            string str = "";
            while (curr->h.size() == 1 and !curr->isTerminal)
            {
                char c = curr->h.begin()->first;
                str = str + c;
                curr = curr->h[c];
            }
            return str;
        }
    };

public:
    string longestCommonPrefix(vector<string> &strs)
    {
        Trie *sol = new Trie;
        for (auto &i : strs)
            sol->insert(i);
        return sol->longestPrefix();
    }
};
// @lc code=end
