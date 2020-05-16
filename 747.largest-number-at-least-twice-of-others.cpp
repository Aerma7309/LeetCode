/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int fl = -1, sl = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (fl == -1 or sl == -1)
            {
                if (fl == -1)
                    fl = i;
                else if (nums[fl] < nums[i])
                {
                    sl = fl;
                    fl = i;
                }
                else
                    sl = i;
            }
            else if (nums[fl] < nums[i])
            {
                sl = fl;
                fl = i;
            }
            else if (nums[sl] < nums[i])
                sl = i;
        }
        if (nums[fl] >= 2 * nums[sl])
            return fl;
        return -1;
    }
};
// @lc code=end
