/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int> &nums)
    {
        // int count=0;
        // for(int i =0; i<nums.size(); i++)
        // {
        //     if(nums[i]==0) count++;
        // }
        int i = 0, j = 0;
        while (j < nums.size())
        {
            if (nums[j] != 0)
                nums[i++] = nums[j++];
            else
                j++;
        }
        while (i < nums.size())
            nums[i++] = 0;
    }
};
// @lc code=end

