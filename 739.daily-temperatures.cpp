/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> v;
        v.resize(T.size());
        stack<pair<int, int>> s; // 0 - value and  1 - index
        for (int i = T.size() - 1; i >= 0; i--)
        {
            while (!s.empty() and s.top().first <= T[i])
                s.pop();
            if (s.empty())
                v[i] = 0;
            else
                v[i] = s.top().second - i;
            s.push({T[i], i});
        }
        return v;
    }
};
// @lc code=end
