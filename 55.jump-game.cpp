/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool findPath(vector<int> &nums, int pos, int dest, int past[])
    {
        if (pos > dest)
            return false;
        if (pos == dest)
            return true;
        if (past[pos] != -1)
            return past[pos];
        for (int a = nums[pos]; a > 0; a--)
            if (findPath(nums, pos + a, dest, past))
                return true;
        return past[pos] = false;
    }

    bool canJump(vector<int> &nums)
    {
        int past[(nums.size() + 5)];
        memset(past, -1, sizeof(past));
        return findPath(nums, 0, nums.size() - 1, past);
    }
};
// @lc code=end

