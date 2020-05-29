/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x,long long n)
    {
        if (n == 0)
            return 1;
        if (x == 1)
            return 1;
        if (n < 0)
            return (long double)1 / myPow(x, -n);
        double smallAnswer = myPow(x, n / 2);
        if (n & 1)
            return x * smallAnswer * smallAnswer;
        return smallAnswer * smallAnswer;
    }
};
// @lc code=end
