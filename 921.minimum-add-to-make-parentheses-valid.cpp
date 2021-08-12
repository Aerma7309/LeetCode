/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<int> stk;
        for (auto &p : s)
        {
            if (stk.empty())
                stk.push(p);
            else if (stk.top() == '(' and p == ')')
                stk.pop();
            else
                stk.push(p);
        }
        return stk.size();
    }
};
// @lc code=end
