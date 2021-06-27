/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 */

// @lc code=start
class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string s = to_string(n);
        bool res = next_permutation(s.begin(), s.end());
        long long num = stoll(s);
        if (not res or num > INT_MAX)
            return -1;
        return num;
    }
};
// @lc code=end
