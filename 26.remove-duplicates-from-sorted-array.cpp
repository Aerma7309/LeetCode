/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i, j, size = nums.size();
        for (i = 0, j = 0; j < size; i++)
        {
            nums[i] = nums[j];
            while (j < size and nums[i] == nums[j])
                j++;
        }
        return i;
    }
};
// @lc code=end
