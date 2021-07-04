// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem76.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        map<char, int> m;
        for (auto &ch : t)
            m[ch]--;
        int len = INT_MAX, start = -1;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            m[s[i]]++;
            bool flag = true;
            for (auto &it : m)
            {
                if (it.second < 0)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                while (j < i)
                {
                    if (m[s[j]])
                    {
                        m[s[j]]--;
                        j++;
                    }
                    else
                        break;
                }
                if (i - j + 1 < len)
                    len = i - j + 1, start = j;
            }
        }
        if (len == INT_MAX)
            return "";
        return s.substr(start, len);
    }
};
// @lc code=end
