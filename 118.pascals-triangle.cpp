/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vv;
        vector<int> prev;
        for (int i = 1; i <= numRows; i++)
        {
            vector<int> curr(prev.size() + 1);
            curr[0] = 1;
            for (int i = 1; i < prev.size(); i++)
                curr[i] = prev[i] + prev[i - 1];
            if (i > 1)
                curr[prev.size()] = 1;
            prev = curr;
            vv.push_back(prev);
        }
        return vv;
    }
};
// @lc code=end
