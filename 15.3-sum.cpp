// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem15.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> v;
        if (nums.size() < 3)
            return v;
        sort(nums.begin(), nums.end());
        for (int pos = 0; pos < nums.size() - 2; pos++)
        {
            if (pos > 0 and nums[pos] == nums[pos - 1]) // skip duplicate
                continue;
            int left = pos + 1, right = nums.size() - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] + nums[pos] == 0)
                    v.push_back({nums[pos], nums[left], nums[right]});
                if (nums[left] + nums[right] + nums[pos] > 0)
                {
                    right--;
                    while (right>=0 and nums[right] == nums[right + 1]) // skip duplicate
                        right--;
                }
                else
                {
                    left++;
                    while (left < nums.size() and nums[left] == nums[left - 1]) // skip duplicate
                        left++;
                }
            }
        }
        return v;
    }
};
// @lc code=end
