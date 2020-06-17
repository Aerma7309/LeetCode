/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int lb = 0, ub = nums.size() - 1, mid;
        while (lb < ub)
        {
            mid = lb + (ub - lb) / 2;
            if (nums[mid] == nums[ub])
                ub--;
            else if (nums[mid] < nums[ub])
                ub = mid;
            else
                lb = mid + 1;
        }
        return nums[lb];
    }
};
// @lc code=end
