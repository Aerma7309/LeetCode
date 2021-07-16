/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        // list<char> l;
        // map<char, list<char>::iterator> m;
        // map<char, bool> f;
        // for (char &i : s)
        // {
        //     if (f.find(i) != f.end())
        //     {
        //         if (m.find(i) != m.end())
        //         {
        //             l.erase(m[i]);
        //             m.erase(i);
        //         }
        //     }
        //     else
        //     {
        //         l.push_back(i);
        //         m[i] = --l.end();
        //         f[i] = true;
        //     }
        // }
        // if (l.empty())
        //     return -1;
        // else
        //     return s.find(l.front());
        map<char, int> m;
        for (auto &ch : s)
            m[ch]++;
        for (int i = 0; i < s.size(); i++)
            if (m[s[i]] == 1)
                return i;
        return -1;
    }
};
// @lc code=end
