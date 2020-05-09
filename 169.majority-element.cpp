/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int me, cnt = 0;
        for (auto i : nums)
        {
            if (cnt == 0)
                me = i, cnt = 1;
            else if (me == i)
                cnt++;
            else
                cnt--;
        }
        return me;
    }
};
// @lc code=end
