/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = max(nums[i] + nums[i - 1], nums[i]);
        }
        int res = *max_element(nums.begin(), nums.end());
        return res;
    }
};
// @lc code=end

