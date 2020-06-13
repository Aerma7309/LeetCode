/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution
{
public:
    void breakWord(string s, set<string> &dict, int pos, const int &maxLength, map<int, vector<string>> &dp)
    {
        if (dp.find(pos) != dp.end())
            return;
        string word = "";
        for (int i = pos; i < s.length() and i < i + maxLength; i++)
        {
            word.push_back(s[i]);
            if (dict.find(word) != dict.end())
            {
                if (i == s.length() - 1)
                    dp[pos].push_back(word);
                else
                {
                    breakWord(s, dict, i + 1, maxLength, dp);
                    for (auto &a : dp[i + 1])
                        dp[pos].push_back(word + " " + a);
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int maxLength = 0;
        set<string> dict(wordDict.begin(), wordDict.end());
        for (auto &i : wordDict)
            maxLength = max(maxLength, (int)i.size());
        map<int, vector<string>> dp;
        breakWord(s, dict, 0, maxLength, dp);
        return dp[0];
    }
};
// @lc code=end
