/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> ms, mt;
        for (int i = 0; i < s.size(); i++)
        {
            if (ms.find(s[i]) == ms.end() and mt.find(t[i]) == mt.end())
            {
                ms[s[i]] = t[i];
                mt[t[i]] = s[i];
            }
            else if (ms.find(s[i]) != ms.end() and mt.find(t[i]) != mt.end())
            {
                if (ms[s[i] != t[i]] or mt[t[i]] != s[i])
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};
// @lc code=end
