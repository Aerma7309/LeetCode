// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem387.h"

using namespace std;
// @before-stub-for-debug-end

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
        // using something like LRU cache making list of
        // contestant and using map to access in constant time
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

        // using map and two traversal of string
        // map<char, int> m;
        // for (auto &ch : s)
        //     m[ch]++;
        // for (int i = 0; i < s.size(); i++)
        //     if (m[s[i]] == 1)
        //         return i;
        // return -1;

        // using map and invalidation trick
        // if char repeats set index as sizeof input string
        map<char, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (m.find(ch) == m.end())
                m[ch] = i;
            else
                m[ch] = s.size();
        }
        int minIndex = s.size();
        for (auto &it : m)
            minIndex = min(minIndex, it.second);
        return minIndex == s.size() ? -1 : minIndex;
    }
};
// @lc code=end
