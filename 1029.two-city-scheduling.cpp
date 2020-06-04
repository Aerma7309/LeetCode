/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */

// @lc code=start
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        if (costs.empty())
            return 0;
        multimap<int, int> m;
        for (int i = 0; i < costs.size(); i++)
            m.insert({(costs[i][1] - costs[i][0]), i});
        int res = 0, cnt = 0;
        for (auto &i : m)
        {
            if (cnt >= (int)m.size() / 2)
                res += costs[i.second][0];
            else
                res += costs[i.second][1];
            cnt++;
        }
        return res;
    }
};
// @lc code=end
