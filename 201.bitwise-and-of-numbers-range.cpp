/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int res = 0;
        for (int i = 30; i >= 0; i--)
        {
            if ((m & (1 << i)) == (n & (1 << i)))
                res |= (m & (1 << i));
            else
                break;
        }
        return res;
    }
};
// @lc code=end

