/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> s;
        for (auto &i : nums)
        {
            if (s.find(i) == s.end())
                s.insert(i);
            else
                return true;
        }
        return false;
    }
};
// @lc code=end
