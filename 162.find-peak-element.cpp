/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int lb = 0, ub = nums.size() - 1, mid, ans = -1;
        while (lb <= ub)
        {
            mid = lb + (ub - lb) / 2;
            if (lb == ub)
            {
                ans = lb;
                break;
            }
            else if (nums[mid] < nums[mid + 1])
                lb = mid + 1;
            else
                ub = mid;
        }
        return ans;
    }
};
// @lc code=end
