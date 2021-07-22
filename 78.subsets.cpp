/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> v;
        for (int i = 0; i < 1 << nums.size(); i++)
        {
            v.clear();
            for (int j = 0; j < 10; j++)
                if (i & (1 << j))
                    v.push_back(nums[j]);
            res.push_back(v);
        }
        return res;
    }
};
// @lc code=end
