/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s1, s2;
        for (auto &i : nums1)
            s1.emplace(i);
        for (auto &i : nums2)
            s2.emplace(i);
        vector<int> res;
        for (auto &i : s1)
            if (s2.find(i) != s2.end())
                res.emplace_back(i);
        return res;
    }
};
// @lc code=end
