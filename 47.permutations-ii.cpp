/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
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
            if (i != s and nums[i] == nums[s])
                continue;
            swap(nums[i], nums[s]);
            permuteHelper(nums, s + 1, e);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(),nums.end());
        permuteHelper(nums, 0, nums.size() - 1);
        return res;
    }
};

// @lc code=end
