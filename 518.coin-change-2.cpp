/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution
{
public:
    int dfs(vector<int> &c, int pos, int amt, vector<vector<int>> &dp)
    {
        if (pos == c.size() or amt < 0)
            return 0;
        if (amt == 0)
            return 1;
        if (dp[amt][pos] != -1)
            return dp[amt][pos];
        return dp[amt][pos] = (dfs(c, pos, amt - c[pos], dp) + dfs(c, pos + 1, amt, dp));
    }

    int change(int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 1;
        vector<vector<int>> past((amount + 1), vector<int>(coins.size(), -1));
        return dfs(coins, 0, amount, past);
    }
};
// @lc code=end
