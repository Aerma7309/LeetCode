/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < A.size() and j < B.size())
        {
            if (max(A[i][0], B[j][0]) <= min(A[i][1], B[j][1]))
                res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
            if (A[i][1] <= B[j][1])
                i++;
            else
                j++;
        }
        return res;
    }
};
// @lc code=end
