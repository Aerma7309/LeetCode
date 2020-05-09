/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        list<char> l;
        map<char, list<char>::iterator> m;
        map<char, bool> f;
        for (char &i : s)
        {
            if (f.find(i) != f.end())
            {
                if (m.find(i) != m.end())
                {
                    l.erase(m[i]);
                    m.erase(i);
                }
            }
            else
            {
                l.push_back(i);
                m[i] = --l.end();
                f[i] = true;
            }
        }
        if (l.empty())
            return -1;
        else
            return s.find(l.front());
    }
};
// @lc code=end
