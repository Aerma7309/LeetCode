/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution
{
public:
    // int removeDuplicates(vector<int> &nums)
    // {
    //     int i, j, size = nums.size();
    //     for (i = 0, j = 0; j < size; i++)
    //     {
    //         nums[i] = nums[j];
    //         while (j < size and nums[i] == nums[j])
    //             j++;
    //     }
    //     return i;
    // }

    int removeDuplicates(vector<int> &nums)
    {
        int i, j, size = nums.size();
        if(size==0) return 0;
        for (i = 1, j = 1; j < size; j++)
        {
            if (nums[j] != nums[j - 1])
                nums[i] = nums[j], i++;
        }
        return i;
    }
};
// @lc code=end
