/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> s;
        s.push(-1);
        map<int, int> m;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (not s.empty() and nums2[i] > s.top())
                s.pop();
            m[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        vector<int> v;
        for (auto &i : nums1)
            v.push_back(m[i]);
        return v;
    }
};
// @lc code=end
