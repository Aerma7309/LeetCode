/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long long m1 = INTMAX_MIN, m2 = INTMAX_MIN, m3 = INTMAX_MIN;
        for (auto &i : nums)
        {
            if (i > m1)
            {
                m3 = m2;
                m2 = m1;
                m1 = i;
            }
            else if (i > m2 and i != m1)
            {
                m3 = m2;
                m2 = i;
            }
            else if (i > m3 and i != m2 and i != m1)
                m3 = i;
        }
        if (m3 == INTMAX_MIN)
            return m1;
        return m3;
    }
};
// @lc code=end
