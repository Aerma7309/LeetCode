/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution
{
public:
    // int findDuplicate(vector<int> &nums)
    // {
    //     set<int> s;
    //     for (auto &i : nums)
    //     {
    //         if (s.find(i) == s.end())
    //             s.emplace(i);
    //         else
    //             return i;
    //     }
    //     return -1;
    // }

    int findDuplicate(vector<int> &nums)
    {
        int hare = 0, tortoise = 0;
        do
        {
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        } while (hare != tortoise);
        hare = 0;
        do
        {
            hare = nums[hare];
            tortoise = nums[tortoise];
        } while (hare != tortoise);
        return hare;
    }
};
// @lc code=end
