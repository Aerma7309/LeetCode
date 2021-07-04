/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // bool searchMatrix(vector<vector<int>> &matrix, int target)
    // {
    //     if (matrix.empty() or matrix[0].empty())
    //         return false;
    //     int r = matrix.size(), c = matrix[0].size();
    //     int s = 0, e = r - 1, row = -1;
    //     while (s <= e)
    //     {
    //         int mid = (s + e) / 2;
    //         if (matrix[mid][c - 1] < target)
    //             s = mid + 1;
    //         else
    //         {
    //             row = mid;
    //             e = mid - 1;
    //         }
    //     }
    //     if (row == -1)
    //         return false;
    //     return binary_search(matrix[row].begin(), matrix[row].end(), target);
    // }
    
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() or matrix[0].empty())
            return false;
        int r = matrix.size(), c = matrix[0].size();
        int s = 0, e = r * c - 1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (matrix[mid / c][mid % c] == target)
                return true;
            else if (matrix[mid / c][mid % c] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return false;
    }
};
// @lc code=end
