/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        int res, a, b;
        for (auto &i : tokens)
        {
            if (i == "+" or i == "-" or i == "*" or i == "/")
            {
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                if (i == "+")
                    res = b + a;
                else if (i == "-")
                    res = b - a;
                else if (i == "*")
                    res = b * a;
                else if (i == "/")
                    res = b / a;
                stk.push(res);
            }
            else
                stk.push(stoi(i));
        }
        return stk.top();
    }
};
// @lc code=end
