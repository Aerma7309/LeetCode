/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() and j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
    }
};
// @lc code=end
