/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty() or grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int depth = 0, goodTomato = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    goodTomato++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        if (not goodTomato)
            return goodTomato;

        while (not q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int curr_x = q.front().first;
                int curr_y = q.front().second;
                for (auto &dir : dirs)
                {
                    int nxt_x = curr_x + dir.first;
                    int nxt_y = curr_y + dir.second;
                    if (nxt_x >= 0 and nxt_x < m and nxt_y >= 0 and nxt_y < n and grid[nxt_x][nxt_y] == 1)
                    {
                        grid[nxt_x][nxt_y] = 2;
                        goodTomato--;
                        q.push({nxt_x, nxt_y});
                    }
                }
                q.pop();
            }
            depth++;
        }

        return goodTomato ? -1 : depth - 1;
    }
};
