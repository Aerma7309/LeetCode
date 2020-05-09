/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    int sumOfDigitSquare(int n)
    {
        if (n == 0)
            return n;
        int res = 0, r;
        r = n % 10;
        res = r * r;
        return res + sumOfDigitSquare(n / 10);
    }

    bool isHappy(int n)
    {
        int fast, slow;
        slow = fast = n;
        do
        {
            fast = sumOfDigitSquare(sumOfDigitSquare(fast));
            slow = sumOfDigitSquare(slow);
        } while (slow != fast);
        return (slow == 1);
    }
};
// @lc code=end

