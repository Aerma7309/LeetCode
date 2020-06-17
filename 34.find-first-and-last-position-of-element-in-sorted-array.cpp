/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (!binary_search(nums.begin(), nums.end(), target))
            return vector<int>{-1, -1};
        int ans1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ans2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return vector<int>{ans1, ans2 - 1};
    }
};
// @lc code=end
