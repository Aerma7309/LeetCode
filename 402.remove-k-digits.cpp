// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem402.h"
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k >= num.size())
            return "0";
        stack<char> s;
        for (auto &i : num)
        {
            if (k > 0 and !s.empty() and s.top() > i)
            {
                while (k > 0 and !s.empty() and s.top() > i)
                {
                    s.pop();
                    k--;
                }
                if (i != '0')
                    s.push(i);
                else if (!s.empty())
                    s.push(i);
            }
            else if(i!='0')
                s.push(i);
            else if(!s.empty()) s.push(i);
        }
        while (k > 0)
        {
            s.pop();
            k--;
        }
        string res = "";
        while (!s.empty())
        {
            res = s.top() + res;
            s.pop();
        }
        if (res.empty())
            return "0";
        return res;
    }
};
// @lc code=end
