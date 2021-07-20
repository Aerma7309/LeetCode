/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    void combinationSum2Helper(vector<int> &candidates, int target, int idx = 0, vector<int> candidateList = {})
    {
        if (target == 0)
        {
            res.push_back(candidateList);
            return;
        }
        if (idx >= candidates.size() or target < 0)
            return;

        for (int i = idx; i < candidates.size(); i++)
        {
            candidateList.push_back(candidates[i]);
            if (i == idx or candidates[i] != candidates[i - 1])
                combinationSum2Helper(candidates, target - candidates[i], i + 1, candidateList);
            candidateList.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        combinationSum2Helper(candidates, target);
        return res;
    }
};
// @lc code=end
