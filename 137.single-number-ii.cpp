/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution
{
public:
    // int singleNumber(vector<int> &nums)
    // {
    //     int ans = 0;
    //     for (int i = 0; i < 32; i++)
    //     {
    //         int cnt = 0;
    //         for (auto &num : nums)
    //             if (num & (1 << i))
    //                 cnt++;
    //         ans |= ((cnt % 3) << i);
    //     }
    //     return ans;
    // }

    int singleNumber(vector<int> &nums)
    {
        int one = 0, two = 0;
        for (auto &num : nums)
        {
            one = (~two) & (one ^ num);
            two = (~one) & (two ^ num);
        }
        return one;
    }
};
// @lc code=end
