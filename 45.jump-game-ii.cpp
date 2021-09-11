/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // N*N doesnot pass
    // int jump(vector<int> &nums)
    // {
    //     vector<int> dp(nums.size(), INT_MAX);
    //     dp[0] = 0;
    //     for (int i = 1; i < nums.size(); i++)
    //         for (int j = 0; j < i; j++)
    //             if (nums[j] + j >= i)
    //                 if (dp[j] != INT_MAX and dp[j] + 1 < dp[i])
    //                     dp[i] = dp[j] + 1;
    //     return dp[nums.size() - 1] != INT_MAX ? dp[nums.size() - 1] : -1;
    // }

    // O(N)
    int jump(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return 0;
        if (nums[0] == 0)
            return -1;
        int maxReach = nums[0], stepsPossible = nums[0], jumps = 1;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            maxReach = max(maxReach, nums[i] + i);
            stepsPossible--;
            if (stepsPossible == 0)
            {
                jumps++;
                if (i >= maxReach)
                    return -1;
                stepsPossible = maxReach - i;
            }
        }
        return jumps;
        
    }
};
// @lc code=end
