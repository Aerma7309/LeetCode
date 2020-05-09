/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num)
    {
        long long lb = 0, ub = num, mid = 0, res;
        while (lb <= ub)
        {
            mid = (lb + ub) / 2;
            if (mid * mid <= num)
                lb = mid + 1, res = mid;
            else
                ub = mid - 1;
        }
        return (res * res == num);
    }
};
// @lc code=end

