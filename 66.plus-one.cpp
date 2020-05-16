/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        auto it = digits.rbegin();
        if (*it < 9)
        {
            *it = *it + 1;
            return digits;
        }
        while (carry > 0 and it < digits.rend())
        {
            int t = *it + carry;
            *it = t % 10;
            carry = t / 10;
            it++;
        }
        if (carry == 0)
            return digits;
        digits.insert(digits.begin(), carry);
        return digits;
    }
};
// @lc code=end
