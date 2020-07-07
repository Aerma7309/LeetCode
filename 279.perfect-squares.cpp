/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution
{
    bool isPerfectSquare(int n) { return (floor(sqrt(n)) == ceil(sqrt(n))); }

public:
    int numSquares(int n)
    {
        if (n <= 3)
            return n;
        if (isPerfectSquare(n))
            return 1;
        for (int i = 1; i * i <= n; i++)
            if (isPerfectSquare(n - i * i))
                return 2;
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;
        return 3;
    }
};
// @lc code=end
