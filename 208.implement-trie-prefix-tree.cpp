/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie
{
    char ch;
    bool isTerminal;
    map<char, Trie *> h;

public:
    /** Initialize your data structure here. */
    Trie(char c='|')
    {
        ch = c;
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
                Trie *newNode = new Trie(i);
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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
