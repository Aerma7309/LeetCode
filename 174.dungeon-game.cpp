/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
int FastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int r = dungeon.size(), c = dungeon[0].size();
        vector<vector<int>> dp(r, vector<int>(c));
        for (int i = r - 1; i >= 0; --i)
        {
            for (int j = c - 1; j >= 0; --j)
            {
                if (i == r - 1 and j == c - 1)
                    dp[i][j] = min(0, dungeon[i][j]);
                else if (i == r - 1)
                    dp[i][j] = min(0, dp[i][j + 1] + dungeon[i][j]);
                else if (j == c - 1)
                    dp[i][j] = min(0, dp[i + 1][j] + dungeon[i][j]);
                else
                    dp[i][j] = min(0, max(dp[i + 1][j], dp[i][j + 1]) + dungeon[i][j]);
            }
        }
        return abs(dp[0][0]) + 1;
    }
};

// @lc code=end
