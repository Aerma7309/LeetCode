/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> copy(heights);
        sort(copy.begin(), copy.end());
        int count;
        for (int i = 0; i < copy.size(); i++)
            if (copy[i] != heights[i])
                count++;
        return count;
    }
};
// @lc code=end
