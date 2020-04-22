class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        stack<char> s, t;
        for (auto &i : S)
        {
            if (i == '#' and !s.empty())
                s.pop();
            else if (i != '#')
                s.push(i);
        }
        for (auto &i : T)
        {
            if (i == '#' and !t.empty())
                t.pop();
            else if (i != '#')
                t.push(i);
        }
        if (s.size() == t.size())
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s.top() == t.top())
                {
                    s.pop();
                    t.pop();
                }
                else
                    return false;
            }
        }
        else
            return false;
        return true;
    }
};