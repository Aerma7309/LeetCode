/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int i = 0, j = 0;
        for (auto &move : moves)
        {
            switch (move)
            {
            case 'U':
                i++;
                break;
            case 'D':
                i--;
                break;
            case 'L':
                j--;
                break;
            case 'R':
                j++;
            }
        }
        return i == 0 and j == 0;
    }
};
// @lc code=end
