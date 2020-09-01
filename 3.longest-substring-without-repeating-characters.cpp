/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
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
    // int lengthOfLongestSubstring(string s)
    // {
    //     int ans = 0;
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         unordered_map<char, bool> m;
    //         for (int j = i; j < s.size(); j++)
    //         {
    //             if (m[s[j]])
    //                 break;
    //             if (ans < j - i+1)
    //                 ans = j - i+1;

    //             m[s[j]] = 1;
    //         }
    //     }
    //     return ans;
    // }

    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        map<char, int> m;
        for (int i = 0, j = -1; i < s.size(); i++)
        {
            if (m.find(s[i]) != m.end())
                j = max(m[s[i]], j);
            m[s[i]] = i;
            ans = max(ans, i - j);
        }
        return ans;
    }
};
// @lc code=end
