/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int globalMax = nums[0], localMax = nums[0], localMin = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int temp = localMax;
            localMax = max({nums[i], nums[i] * localMax, nums[i] * localMin});
            localMin = min({nums[i], nums[i] * temp, nums[i] * localMin});
            globalMax = max(globalMax, localMax);
        }
        return globalMax;
    }
};
// @lc code=end
