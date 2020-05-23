// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem498.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty() or matrix[0].empty())
            return vector<int>{};
        int row = matrix.size(), col = matrix[0].size();
        vector<int> res;
        res.reserve(row * col);
        auto isValid = [&](int i, int j) -> bool {
            return (i >= 0 and i < row and j >= 0 and j < col);
        };
        int i = 0, j = 0;
        bool isUpward = true;
        while (i < row and j < col)
        {
            res.push_back(matrix[i][j]);
            if (isUpward)
            {
                if (isValid(i - 1, j + 1))
                {
                    i = i - 1;
                    j = j + 1;
                }
                else
                {
                    if (isValid(i, j + 1))
                        j = j + 1;
                    else
                        i = i + 1;
                    isUpward = !isUpward;
                }
            }
            else
            {
                if (isValid(i + 1, j - 1))
                {
                    i = i + 1;
                    j = j - 1;
                }
                else
                {
                    if (isValid(i + 1, j))
                        i = i + 1;
                    else
                        j = j + 1;
                    isUpward = !isUpward;
                }
            }
        }
        return res;
    }
};
// @lc code=end
