/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution
{
public:
    // int findDuplicate(vector<int> &nums)
    // {
    //     set<int> s;
    //     for (auto &i : nums)
    //     {
    //         if (s.find(i) == s.end())
    //             s.emplace(i);
    //         else
    //             return i;
    //     }
    //     return -1;
    // }

    int findDuplicate(vector<int> &nums)
    {
        int i;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i])] > 0)
                nums[abs(nums[i])] *= (-1);
            else
                break;
        }
        return abs(nums[i]);
    }
};
// @lc code=end
