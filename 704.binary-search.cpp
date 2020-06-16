/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int lb = 0, ub = nums.size() - 1, mid, ans = -1;
        while (lb <= ub)
        {
            mid = (lb + ub) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                break;
            }
            else if (nums[mid] > target)
                ub = mid - 1;
            else
                lb = mid + 1;
        }
        return ans;
    }
};
// @lc code=end
