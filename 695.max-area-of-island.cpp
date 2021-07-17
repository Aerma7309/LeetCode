/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{

private:
    int dfs(vector<vector<int>> &grid, int r, int c, int i, int j)
    {
        if (i < 0 or j < 0 or i >= r or j >= c or grid[i][j] != 1)
            return 0;
        grid[i][j] = 2;
        int cnt = 1;
        cnt += dfs(grid, r, c, i - 1, j);
        cnt += dfs(grid, r, c, i + 1, j);
        cnt += dfs(grid, r, c, i, j - 1);
        cnt += dfs(grid, r, c, i, j + 1);
        return cnt;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        if (c == 0)
            return 0;
        int ans = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == 1)
                    ans = max(ans, dfs(grid, r, c, i, j));
        return ans;
    }
};
// @lc code=end
