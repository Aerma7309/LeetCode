/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] cnt Square Submatrices with All Ones
 */

// @lc code=start
class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        if (matrix.empty() or matrix[0].empty())
            return 0;
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size()));
        int cnt = 0;
        for (int i = 0; i < matrix.size(); i++)
            res[i][0] = matrix[i][0];
        for (int i = 0; i < matrix[0].size(); i++)
            res[0][i] = matrix[0][i];
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j])

                    res[i][j] = min({res[i][j - 1], res[i - 1][j], res[i - 1][j - 1]}) + 1;
                else
                    res[i][j] = 0;
            }
        }
        for (auto &i : res)
            for (auto &j : i)
                cnt += j;
        return cnt;
    }
};
// @lc code=end
