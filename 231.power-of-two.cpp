/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution
{
public:
    // bool isPowerOfTwo(int n)
    // {
    //     while (n > 0)
    //     {
    //         if (n == 1)
    //             return true;
    //         else if (n & 1)
    //             return false;
    //         else
    //             n >>= 1;
    //     }
    //     return false;
    // }

    bool isPowerOfTwo(int n)
    {
        return n > 0 and not(n & (n - 1));
    }
};
// @lc code=end
