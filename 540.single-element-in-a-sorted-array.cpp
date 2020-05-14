/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int size = nums.size(), lb = 0, ub = size, mid, res = 0;
        if(size==1) return nums[0];
        while (lb <= ub)
        {
            mid = (lb + ub) / 2;
            if (mid & 1 and nums[mid] == nums[mid - 1])
                lb = mid + 1;
            else if (!(mid & 1) and nums[mid] == nums[mid + 1])
                lb = mid + 1;
            else ub = mid-1,res=ub;
        }
        return nums[res+1];
    }
};
// @lc code=end
