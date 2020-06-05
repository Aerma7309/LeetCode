/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> v(num + 1);
        for (int i = 1; i <= num; i++)
        {
            if (i & 1)
                v[i] = v[i / 2] + 1;
            else
                v[i] = v[i / 2];
        }
        return v;
    }
};
// @lc code=end
