/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int rows = matrix.size();
        if (rows == 0)
            return 0;
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols));
        int largest = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 or j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                    largest = max(largest, dp[i][j]);
                }
            }
        }
        return largest * largest;
    }
};
// @lc code=end

