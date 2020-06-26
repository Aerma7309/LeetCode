/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<char>> &board, int i, int j, int row, int col)
    {
        if (i < 0 or j < 0 or i >= row or j >= col)
            return;
        if (board[i][j] != 'O')
            return;
        board[i][j] = '1';
        dfs(board, i - 1, j, row, col);
        dfs(board, i + 1, j, row, col);
        dfs(board, i, j - 1, row, col);
        dfs(board, i, j + 1, row, col);
    }
    void solve(vector<vector<char>> &board)
    {
        if (board.empty() or board[0].empty())
            return;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < col; i++)
        {
            if (board[0][i] == 'O')
                dfs(board, 0, i, row, col);
            if (board[row - 1][i] == 'O')
                dfs(board, row - 1, i, row, col);
        }
        for (int i = 0; i < row; i++)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0, row, col);
            if (board[i][col - 1] == 'O')
                dfs(board, i, col - 1, row, col);
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }
};
// @lc code=end
