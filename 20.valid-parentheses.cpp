/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.empty())
            return true;
        stack<char> stk;
        for (auto &ch : s)
        {
            if (stk.empty() or ch == '(' or ch == '{' or ch == '[')
                stk.push(ch);
            else
            {
                switch (ch)
                {
                case ')':
                    if (!stk.empty() and stk.top() == '(')
                        stk.pop();
                    else
                        return false;
                    break;
                case '}':
                    if (!stk.empty() and stk.top() == '{')
                        stk.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (!stk.empty() and stk.top() == '[')
                        stk.pop();
                    else
                        return false;
                    break;
                }
            }
        }
        return stk.empty();
    }
};
// @lc code=end
