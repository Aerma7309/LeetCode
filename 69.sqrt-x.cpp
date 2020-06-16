/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        long long lb = 0, ub = x, mid;
        int ans = -1;
        while (lb <= ub)
        {
            mid = (lb + ub) / 2;
            if (mid * mid <= x)
            {
                ans = mid;
                lb = mid + 1;
            }
            else
                ub = mid - 1;
        }
        return ans;
    }
};
// @lc code=end
