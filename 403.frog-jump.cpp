/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    map<pair<int, int>, int> dp;
    bool canCrossHelper(set<int> &s, int curr, int jumpWidth)
    {
        if (s.find(curr) == s.end()) // landing on water return false
            return false;
        if (dp.find({curr, jumpWidth}) != dp.end())
            return dp[{curr, jumpWidth}];
        if (curr == (*s.rbegin())) //landing on last stone i.e river is crossed
            return true;
        bool res = false;
        if (jumpWidth > 1)
            res |= canCrossHelper(s, curr + jumpWidth - 1, jumpWidth - 1);
        if (jumpWidth > 0)
            res |= canCrossHelper(s, curr + jumpWidth, jumpWidth);
        res |= canCrossHelper(s, curr + jumpWidth + 1, jumpWidth + 1);
        return dp[{curr, jumpWidth}] = res;
    }
    bool canCross(vector<int> &stones)
    {
        if (stones.size() < 2)
            return true;
        set<int> s(stones.begin(), stones.end());
        return canCrossHelper(s, 0, 0);
    }
};
// @lc code=end
