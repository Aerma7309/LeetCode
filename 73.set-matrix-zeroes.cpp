/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // void setZeroes(vector<vector<int>> &matrix)
    // {
    //     set<int> r, c;
    //     for (int i = 0; i < matrix.size(); i++)
    //     {
    //         for (int j = 0; j < matrix[0].size(); j++)
    //         {
    //             if (matrix[i][j] == 0)
    //                 r.insert(i), c.insert(j);
    //         }
    //     }
    //     for (int i = 0; i < matrix.size(); i++)
    //     {
    //         for (int j = 0; j < matrix[0].size(); j++)
    //         {
    //             if (r.find(i) != r.end() or c.find(j) != c.end())
    //                 matrix[i][j] = 0;
    //         }
    //     }
    // }

    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        bool r0Zero = false, c0Zero = false;
        for (int i = 0; i < rows; i++)
            if (matrix[i][0] == 0)
                c0Zero = true;

        for (int i = 0; i < cols; i++)
            if (matrix[0][i] == 0)
                r0Zero = true;

        for (int i = 1; i < rows; i++)
            for (int j = 1; j < cols; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = 0, matrix[0][j] = 0;

        for (int i = 1; i < rows; i++)
            for (int j = 1; j < cols; j++)
                if (matrix[i][0] == 0 or matrix[0][j] == 0)
                    matrix[i][j] = 0;

        if (r0Zero)
        {
            for (int i = 0; i < cols; i++)
                matrix[0][i] = 0;
        }
        if (c0Zero)
        {
            for (int i = 0; i < rows; i++)
                matrix[i][0] = 0;
        }
    }
};
// @lc code=end
