/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[i] + nums[j] == target)
        //             return vector<int>{i, j};
        //     }
        // }
        // return vector<int>{};

        map<int, int> h;
        for (int i = 0; i < nums.size(); i++)
        {
            if (h.find(target - nums[i]) != h.end())
                return vector<int>{h[target - nums[i]], i};
            else
                h[nums[i]] = i;
        }
        return vector<int>{};
    }
};
// @lc code=end
