/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        long long ans = 0;
        int num = abs(x);
        while (num>0)
        {
            ans = ans * 10 + num % 10;
            num /= 10;
        }
        if (x < 0)
            ans *= -1;
        if (ans < INT_MIN or ans > INT_MAX)
            return 0;
        return ans;
    }
};
// @lc code=end
