/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#pragma GCC optimize(Ofast)
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
    bool isValidSudoku(vector<vector<char>> &board)
    {
        short h[9] = {}, v[9] = {}, d[9] = {};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0', diag = ((i / 3) * 3 + (j / 3));
                    if (h[i] & (1 << num) or v[j] & (1 << num) or d[diag] & (1 << num))
                        return false;
                    h[i] |= (1 << num);
                    v[j] |= (1 << num);
                    d[diag] |= (1 << num);
                }
            }
        }
        return true;
    }
};
// @lc code=end
