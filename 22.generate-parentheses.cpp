/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution
{
public:
    vector<string> v;
    void generateParenthesisHelper(int n, int open, int close, string res)
    {
        if (res.size() == 2 * n)
        {
            v.emplace_back(res);
            return;
        }
        if (open < n)
            generateParenthesisHelper(n, open + 1, close, res + '(');
        if (open > close)
            generateParenthesisHelper(n, open, close + 1, res + ')');
    }
    vector<string> generateParenthesis(int n)
    {

        generateParenthesisHelper(n, 0, 0, "");
        return v;
    }
};
// @lc code=end
