/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int fnSum = 0, total = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            fnSum += i * nums[i], total += nums[i];

        int res = fnSum;
        for (int i = 0; i < n - 1; i++)
        {
            fnSum += (n)*nums[i] - total;
            // same as (n-1)*nums[i] - total+nums[i];
            // as we need to subtract sumof all except self
            res = max(res, fnSum);
        }
        return res;
    }
};
// @lc code=end
