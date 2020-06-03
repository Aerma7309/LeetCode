/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution
{
public:
    bool canPlace(vector<vector<char>> &board, int i, int j, int num)
    {
        for (int x = 0; x < 9; x++)
            if (board[i][x] - '0' == num or board[x][j] - '0' == num)
                return false;
        i = (i / 3) * 3;
        j = (j / 3) * 3;
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                if (board[i + r][j + c] - '0' == num)
                    return false;
        return true;
    }

    bool solveSudoku(vector<vector<char>> &board, int i = 0, int j = 0)
    {
        if (i == 9)
            return true;
        if (j == 9)
            return solveSudoku(board, i + 1, 0);
        if (board[i][j] != '.')
            return solveSudoku(board, i, j + 1);
        for (int x = 1; x <= 9; x++)
        {
            if (canPlace(board, i, j, x))
            {
                board[i][j] = x + '0';
                if (solveSudoku(board, i, j + 1))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
};
// @lc code=end
