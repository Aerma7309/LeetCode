/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int a = 0, b = nums[0], c = nums[0];
        for (int i = 1; i < nums.size(); i++)
            c = max(nums[i] + a, b), a = b, b = c;
        return c;
    }
};
// @lc code=end
