/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty() or matrix[0].empty())
            return vector<int>{};
        int row = matrix.size(), col = matrix[0].size();
        int cl = 0, ch = col, rl = 0, rh = row;
        vector<int> res;
        res.reserve(row * col);
        while (rh > rl and ch > cl)
        {
            for (int c = cl; c < ch; c++)
                res.push_back(matrix[rl][c]);
            rl++;
            for (int r = rl; r < rh;r++)
                res.push_back(matrix[r][ch - 1]);
            ch--;
            if(rh!=rl)
            {
                for (int c = ch - 1; c >= cl; c--)
                    res.push_back(matrix[rh - 1][c]);
                rh--;
            }
            if(ch!=cl)
            {
                for (int r = rh - 1; r >= rl; r--)
                    res.push_back(matrix[r][cl]);
                cl++;
            }
        }
        return res;
    }
};
// @lc code=end
