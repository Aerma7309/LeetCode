/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int i = -1, j = 0, size = nums.size(), res = 0;
        while (i < size and j < size)
        {
            if (nums[j])
                res = max(res, j - i);
            else
                i = j;
            ++j;
        }
        return res;
    }
};
// @lc code=end

