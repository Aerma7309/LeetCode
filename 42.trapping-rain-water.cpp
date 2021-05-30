/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(), ans = 0;
        if (n == 0)
            return n;
        vector<int> left_max(n), right_max(n);
        left_max[0] = right_max[n - 1] = 0;
        for (int i = 1; i < n - 1; i++)
        {
            left_max[i] = max(left_max[i - 1], height[i - 1]);
            right_max[n - i - 1] = max(right_max[n - i], height[n - i]);
        }
        for (int i = 1; i < n - 1; i++)
            ans += max(min(left_max[i], right_max[i]) - height[i], 0);
        return ans;
    }
};
// @lc code=end
