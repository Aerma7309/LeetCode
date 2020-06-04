/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
class Solution
{
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B)
    {
        vector<vector<int>> past(A.size() + 1, vector<int>(B.size() + 1));
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                if (A[i] == B[j])
                    past[i + 1][j + 1] = past[i][j] + 1;
                else
                    past[i + 1][j + 1] = max(past[i + 1][j], past[i][j + 1]);
            }
        }
        return past[A.size()][B.size()];
    }
};
// @lc code=end
