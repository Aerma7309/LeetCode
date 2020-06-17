/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int lb = 0, ub = nums.size() - 1, mid;
        if (nums[lb] <= nums[ub])
            return nums[lb];
        while (lb < ub)
        {
            mid = lb + (ub - lb) / 2;
            if (nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            else if (nums[mid] > nums[lb])
                lb = mid + 1;
            else
                ub = mid;
        }
        return -1;
    }
};
// @lc code=end
