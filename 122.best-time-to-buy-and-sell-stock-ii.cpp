/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int ans = 0;
    int maxProfit(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1])
                ans += nums[i + 1] - nums[i];
        }
        return ans;
    }
};
// @lc code=end

