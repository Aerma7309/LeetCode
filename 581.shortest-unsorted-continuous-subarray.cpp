/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
    function<bool(vector<int> &, int)> outOfOrder = [&](vector<int> &v, int i)
    {
        if (i == 0)
            return v[i] > v[i + 1];
        else if (i == v.size() - 1)
            return v[i] < v[i - 1];
        return v[i] > v[i + 1] or v[i] < v[i - 1];
    };

public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        if(nums.size()<2) return 0;
        int mx = INT_MIN, mn = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (outOfOrder(nums, i))
            {
                mx = max(mx, nums[i]);
                mn = min(mn, nums[i]);
            }
        }
        if (mn == INT_MAX)
            return 0;
        int left = 0;
        while (mn >= nums[left])
            left++;
        int right = nums.size() - 1;
        while (mx <= nums[right])
            right--;
        return right - left + 1;
    }
};
// @lc code=end
