/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution
{
public:
    // int fib(int N) {
    //     if(N==0 or N==1) return N;
    //     return fib(N-1)+fib(N-2);
    // }

    int fib(int N)
    {
        int a = 0, b = 1, c = 0;
        if (N < 2)
            return N;
        for (int i = 2; i <= N; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
// @lc code=end
