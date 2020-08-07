/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
int FastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    bool cycle_detector_helper(int node, bool path[], bool vis[], vector<int> graph[])
    {
        vis[node] = true;
        path[node] = true;
        for (auto &&nbr : graph[node])
        {
            if (path[nbr])
                return true;
            else if (not vis[nbr])
            {
                bool cycle_ahead = cycle_detector_helper(nbr, path, vis, graph);
                if (cycle_ahead)
                    return true;
            }
        }
        path[node] = false;
        return false;
    }

    void dfs(int node, bool vis[], vector<int> graph[], vector<int> &res)
    {
        vis[node] = true;
        for (auto &&nbr : graph[node])
            if (not vis[nbr])
                dfs(nbr, vis, graph, res);
        res.emplace_back(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        bool path[numCourses], visited[numCourses], cycle_found = false;
        for (int i = 0; i < numCourses; i++)
            path[i] = visited[i] = false;
        vector<int> graph[numCourses];
        for (auto &&i : prerequisites)
            graph[i[0]].emplace_back(i[1]);
        for (int i = 0; i < numCourses; i++)
            if (not visited[i])
                if (cycle_detector_helper(i, path, visited, graph))
                    return {};
        vector<int> res;
        for (int i = 0; i < numCourses; i++)
            visited[i] = false;
        for (int i = 0; i < numCourses; i++)
            if (not visited[i])
                dfs(i, visited, graph, res);
        return res;
    }
};
// @lc code=end
