/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        for (int i = -1, j = -1, k = 0; k < nums.size(); k++)
        {
            if (nums[k] == 1)
                swap(nums[++j], nums[k]);
            else if (nums[k] == 0)
            {
                swap(nums[++j], nums[k]);
                swap(nums[++i], nums[j]);
            }
        }
    }
};
// @lc code=end
