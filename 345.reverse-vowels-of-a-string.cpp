/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        string v = "aeiouAEIOU";
        set<char> vowels(v.begin(), v.end());
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            while (i < j and vowels.find(s[i]) == vowels.end())
                i++;
            while (j > i and vowels.find(s[j]) == vowels.end())
                j--;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};
// @lc code=end
