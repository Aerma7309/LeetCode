// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem84.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(0);
        stack<int> s;
        int ans = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (not s.empty() and heights[s.top()] > heights[i])
            {
                int ht = heights[s.top()];
                s.pop();
                if (s.empty())
                    ans = max(ans, i * ht);
                else
                    ans = max(ans, (i - s.top() - 1) * ht);
            }
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end
