/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xr = 0;
        for (auto &i : nums)
        {
            xr ^= i;
        }
        return xr;
    }
};
// @lc code=end
