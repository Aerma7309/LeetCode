/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if(needle.empty()) return 0;
        for (int i = 0; i < haystack.size(); i++)
            if (haystack.substr(i, needle.size()) == needle)
                return i;
        return -1;
    }
};
// @lc code=end
