/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        long long ans = 1, j = 2;
        for (long long i = n + 2; i <= 2 * n; i++)
        {
            ans *= i;
            if (ans % j == 0)
                ans /= j++;
        }
        while (j <= n)
            ans /= j++;
        return ans;
    }
};
// @lc code=end
