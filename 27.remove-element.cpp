/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int> &nums, int val)
    {
        int s = nums.size();
        int c = count(nums.begin(), nums.end(), val);
        for (int i = 0, j = s - 1; i < s - c; i++)
        {
            if (nums[i] == val)
            {
                while (nums[j] == val)
                    j--;
                swap(nums[i], nums[j]);
            }
        }
        return s - c;
    }
};
// @lc code=end

