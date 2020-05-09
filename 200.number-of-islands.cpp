/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    void markConnected(int i, int j, vector<vector<char>> &grid, int r, int c)
    {
        if (i < 0 or j < 0 or i >= r or j >= c)
            return;
        if (grid[i][j] != '1')
            return;
        grid[i][j] = 'm';
        markConnected(i, j + 1, grid, r, c);
        markConnected(i + 1, j, grid, r, c);
        markConnected(i, j - 1, grid, r, c);
        markConnected(i - 1, j, grid, r, c);
    }
    int cnt = 0;
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0)
            return 0;
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '1')
                {
                    cnt++;
                    markConnected(i, j, grid, r, c);
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

