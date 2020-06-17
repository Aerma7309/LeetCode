// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem350.h"
#include<bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> s1, s2;
        for (auto &i : nums1)
            s1[i]++;
        for (auto &i : nums2)
            s2[i]++;
        vector<int> res;
        for (auto &i : s1)
            if (s2.find(i.first) != s2.end())
                res.insert(res.end(),min(s1[i.first], s2[i.first]) ,i.first);
        return res;
    }
};
// @lc code=end
