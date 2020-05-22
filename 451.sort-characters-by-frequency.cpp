/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> m;
        for (auto &i : s)
            m[i]++;
        multimap<int, char, greater<int>> r;
        for (auto &i : m)
            r.insert({i.second, i.first});
        int pos = 0;
        for (auto &i : r)
        {
            int c = i.first;
            while (c--)
            {
                s[pos++] = i.second;
            }
        }
        return s;
    }
};
// @lc code=end
