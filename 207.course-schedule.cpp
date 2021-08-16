/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
    bool detect_cycle(vector<vector<int>> &g, set<int> &vis, set<int> &path, int curr)
    {
        vis.insert(curr);
        path.insert(curr);
        for (auto nbr : g[curr])
        {
            if (vis.find(nbr) == vis.end())
            {
                if (detect_cycle(g, vis, path, nbr))
                    return true;
            }
            else if (path.find(nbr) != path.end())
                return true;
        }
        path.erase(curr);
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> g(numCourses);
        for (auto &pre : prerequisites)
            g[pre[0]].push_back(pre[1]);
        set<int> vis, path;
        for (auto &pre : prerequisites)
            if (vis.find(pre[0]) == vis.end() and detect_cycle(g, vis, path, pre[0]))
                return false;
        return true;
    }
};
// @lc code=end
