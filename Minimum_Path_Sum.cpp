class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
            return 0;
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> path(r, vector<int>(c));
        path[0][0] = grid[0][0];
        for (int i = 1; i < r; i++)
            path[i][0] = path[i - 1][0] + grid[i][0];
        for (int i = 1; i < c; i++)
            path[0][i] = path[0][i - 1] + grid[0][i];
        for (int i = 1; i < r; i++)
            for (int j = 1; j < c; j++)
                path[i][j] = min(path[i - 1][j], path[i][j - 1]) + grid[i][j];
        return path[r - 1][c - 1];
    }
};