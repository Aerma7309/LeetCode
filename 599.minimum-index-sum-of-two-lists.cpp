/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */

// @lc code=start
class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); i++)
            m[list1[i]] = i;
        int ansv = INT_MAX;
        vector<string> res;
        for (int i = 0; i < list2.size(); i++)
        {
            if (m.find(list2[i]) != m.end())
            {
                if (ansv > (i + m[list2[i]]))
                {
                    res.clear();
                    ansv = i + m[list2[i]];
                    res.emplace_back(list2[i]);
                }
                else if (ansv == (i + m[list2[i]]))
                    res.emplace_back(list2[i]);
            }
        }
        return res;
    }
};
// @lc code=end
