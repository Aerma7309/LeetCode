/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int s1 = text1.size(), s2 = text2.size();
        int past[s1 + 1][s2 + 1];
        memset(past, 0, sizeof(past));
        for (int i = 1; i <= s1; i++)
            for (int j = 1; j <= s2; j++)
                if (text1[i - 1] == text2[j - 1])
                    past[i][j] = past[i - 1][j - 1] + 1;
                else
                    past[i][j] = max(past[i - 1][j], past[i][j - 1]);
        return past[s1][s2];
    }
};
// @lc code=end

