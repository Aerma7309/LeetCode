/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int myAtoi(string s)
    {
        long long res = 0, sign = 1, i = 0;
        while (i < s.size() and s[i] == ' ')
            i++;
        if (s[i] == '-')
            sign = -1;
        if (s[i] == '+' or s[i] == '-')
            s = s.substr(i + 1);
        else
            s = s.substr(i);

        for (auto &ch : s)
        {
            if (ch - '0' >= 0 and ch - '0' <= 9)
            {
                res = res * 10 + (ch - '0');
                if (res * sign >= INT_MAX)
                    return INT_MAX;
                if (res * sign <= INT_MIN)
                    return INT_MIN;
            }
            else
                break;
        }
        return res * sign;
    }
};
// @lc code=end
