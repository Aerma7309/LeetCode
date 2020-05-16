/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int size = nums.size();
        int sum = 0;
        for (auto &i : nums)
            sum += i;
        int left = 0, right = sum;
        for (int i = 0; i < nums.size(); i++)
        {
            if (left == right - nums[i])
                return i;
            left += nums[i];
            right -= nums[i];
        }
        return -1;
    }
};
// @lc code=end
