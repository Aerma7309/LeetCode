/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    void permuteHelper(vector<int> nums, int s, int e)
    {
        if (s == e)
        {
            res.emplace_back(nums);
            return;
        }
        for (int i = s; i <= e; i++)
        {
            swap(nums[i], nums[s]);
            permuteHelper(nums, s + 1, e);
            swap(nums[i], nums[s]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        permuteHelper(nums, 0, nums.size() - 1);
        return res;
    }
};
// @lc code=end
