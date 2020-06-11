/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution
{
public:
    int DONE;
    void countWays(int rowMask, int leftDiagonal, int rightDiagonal, int &count)
    {
        if (rowMask == DONE)
        {
            count++;
            return;
        }
        int safe = DONE & (~(rowMask | leftDiagonal | rightDiagonal));
        while (safe)
        {
            int p = safe & (-safe);
            countWays(rowMask | p, (leftDiagonal | p) << 1, (rightDiagonal | p) >> 1, count);
            safe = safe - p;
        }
    }

    int totalNQueens(int n)
    {
        int count = 0;
        DONE = (1 << n) - 1;
        countWays(0, 0, 0, count);
        return count;
    }
};
// @lc code=end

