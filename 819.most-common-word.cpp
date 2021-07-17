/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        for (auto &ch : paragraph)
            if (not isalpha(ch))
                ch = ' ';
            else if (isupper(ch))
                ch += 32;
        set<string> bannedWords(banned.begin(), banned.end());
        map<string, int> freq;
        stringstream ss(paragraph);
        string str;
        while (ss >> str)
        {
            if (bannedWords.find(str) == bannedWords.end())
                freq[str]++;
        }
        return (max_element(freq.begin(), freq.end(), [](auto a, auto b)
                            { return a.second < b.second; }))
            ->first;
    }
};
// @lc code=end
