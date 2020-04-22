class Solution
{
public:
    // you can do it with two stack
    bool checkValidString(string s)
    {
        stack<int> stk;
        vector<int> star;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
                star.push_back(i);
            else if (s[i] == '(')
                stk.push(i);
            else if (s[i] == ')')
            {
                if (!stk.empty())
                    stk.pop();
                else if (star.size() > 0)
                    star.pop_back();
                else
                    return false;
            }
        }
        while (!stk.empty() and star.size() > 0)
        {
            if (stk.top() < star.back())
            {
                stk.pop();
                star.pop_back();
            }
            else
                return false;
        }
        return stk.empty();
    }
};