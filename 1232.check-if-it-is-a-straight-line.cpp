/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 */

// @lc code=start
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &points)
    {
        int x_diff = abs(points[0][0] - points[1][0]);
        int y_diff = abs(points[0][1] - points[1][1]);
        for (int i = 1; i < points.size() - 1; i++)
        {
            int currx_diff = abs(points[i][0] - points[i + 1][0]);
            int curry_diff = abs(points[i][1] - points[i + 1][1]);
            if ((y_diff * currx_diff) != (curry_diff * x_diff))
                return false;
        }
        return true;
    }
};
// @lc code=end
