/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> q;
        vector<int> res;
        auto add = [&](int i)
        {
            while (not q.empty() and nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
            while (not q.empty() and q.front() <= i - k)
                q.pop_front();
        };
        for (int i = 0; i < nums.size(); i++)
        {
            add(i);
            if (i >= k - 1)
                res.push_back(nums[q.front()]);
        }
        return res;
    }
};
// @lc code=end
