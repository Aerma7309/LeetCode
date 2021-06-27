/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size(), lr = INT_MIN;
        stack<int> s;
        vector<int> v(n, -1);
        for (int i = 0; i < n * 2; i++)
        {
            int curr = nums[i % n];
            if (lr == INT_MIN and curr > nums.back())
                lr = curr;
            while (not s.empty() and curr > nums[s.top()])
            {
                v[s.top()] = curr;
                s.pop();
            }
            s.push(i % n);
        }
        if (lr != INT_MIN)
            v.back() = lr;
        return v;
    }
};
// @lc code=end
