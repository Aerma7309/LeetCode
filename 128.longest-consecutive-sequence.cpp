/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (auto &num : nums)
        {
            if (s.find(num - 1) == s.end())
            {
                int t = num + 1;
                while (s.find(t) != s.end())
                    t++;
                ans = max(ans, t - num);
            }
        }
        return ans;
    }
};
// @lc code=end
