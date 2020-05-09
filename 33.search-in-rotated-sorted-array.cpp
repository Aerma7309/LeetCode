/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();
        int lb = 0, ub = len - 1, mid;
        while (lb <= ub)
        {
            mid = (lb + ub) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] >= nums[0])
            {
                if (target <= nums[mid] and target >= nums[0])
                    ub = mid - 1;
                else
                    lb = mid + 1;
            }
            else
            {
                if (target >= nums[mid] and target <= nums[len - 1])
                    lb = mid + 1;
                else
                    ub = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

