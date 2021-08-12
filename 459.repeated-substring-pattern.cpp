/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // bool canMake(string &s, int sz)
    // {
    //     if (sz == 0 or s.size() % sz)
    //         return false;
    //     string sub = s.substr(0, sz);
    //     int j = 0;
    //     for (; j < s.size(); j++)
    //         if (sub[j % sz] != s[j])
    //             break;
    //     if (j == s.size())
    //         return true;
    //     sub = sub.substr(1);
    //     return false;
    // }
    // bool repeatedSubstringPattern(string s)
    // {
    //     for (int i = 1; i < s.size(); i++)
    //         if (canMake(s, i))
    //             return true;
    //     return false;
    // }

    // bool repeatedSubstringPattern(string s)
    // {
    //     /*
    //      The key here is to double the string, that is, append the string to itself.
    //      In this way, the pattern would be duplicated.
    //      On removing the first and the last characters, if there exists some pattern,
    //      we would still be able to find the original string somewhere in the middle,
    //      taking some characters from the first half and some from the second half.
    //     */
    //     return (s + s).substr(1, 2 * s.size() - 2).find(s) != -1;
    // }

    bool repeatedSubstringPattern(string s)
    {
        //using above approach using KMP string matching
        string text = (s + s).substr(1, 2 * s.size() - 2);
        vector<int> pi(s.size() + 1);
        int i = 1, len = 0;
        while (i < s.size())
        {
            if (s[i] == s[len])
            {
                len++;
                pi[i] = len;
                i++;
            }
            else
            {
                if (len > 0)
                    len = pi[len - 1];
                else
                {
                    len = 0;
                    i++;
                }
            }
        }

        i = 0, len = 0;
        while (i < text.size())
        {
            if (text[i] == s[len])
            {
                len++;
                i++;
            }
            if (len == s.size())
                return true;
            else if (i < text.size() and s[len] != text[i])
            {
                if (len > 0)
                    len = pi[len - 1];
                else
                    i++;
            }
        }
        return false;
    }
};
// @lc code=end
