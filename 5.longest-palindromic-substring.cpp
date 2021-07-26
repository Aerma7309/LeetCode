/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // string longestPalindrome(string s)
    // {
    //     string ans = "";
    //     int n = s.size();
    //     vector<vector<bool>> dp(n, vector<bool>(n, false));
    //     for (int size = 1; size <= n; size++)
    //     {
    //         for (int j = size - 1, i = 0; i < n and j < n; i++, j++)
    //         {
    //             if (size == 1)
    //                 dp[i][j] = true;
    //             else if (size == 2)
    //                 dp[i][j] = s[i] == s[j];
    //             else
    //             {
    //                 if (s[i] == s[j])
    //                     dp[i][j] = dp[i + 1][j - 1];
    //                 else
    //                     dp[i][j] = false;
    //             }
    //             if (dp[i][j] and ans.size() < j - i + 1)
    //                 ans = s.substr(i, j - i + 1);
    //         }
    //     }
    //     return ans;
    // }

    string longestPalindrome(string s)
    {
        int idx = 0, size = 1, n = s.size();
        for (int i = 1; i < n; i++)
        {
            int oddLen = 1, evenLen, a = i - 1, b = i + 1;
            while (a >= 0 and b < n and s[a] == s[b])
            {
                oddLen += 2;
                a--;
                b++;
            }
            evenLen = 0, a = i - 1, b = i;
            while (a >= 0 and b < n and s[a] == s[b])
            {
                evenLen += 2;
                a--;
                b++;
            }

            int len = max(oddLen, evenLen);
            if (size < len)
            {
                idx = i - len / 2;
                size = len;
            }
        }
        return s.substr(idx, size);
    }
};
// @lc code=end
