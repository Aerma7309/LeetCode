/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        long long lb = 1, ub = n, mid, ans;
        while (lb <= ub)
        {
            mid = (lb + ub) / 2;
            ans = guess(mid);
            if (ans == 0)
                break;
            else if (ans == 1)
                lb = mid + 1;
            else
                ub = mid - 1;
        }
        return mid;
    }
};
// @lc code=end
