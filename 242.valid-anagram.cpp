/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> freq(256);
        for (auto &ch : s)
            freq[ch]--;
        for (auto &ch : t)
            freq[ch]++;
        for (auto &f : freq)
            if (f != 0)
                return false;
        return true;
    }
};
// @lc code=end
