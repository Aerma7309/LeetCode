/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
class Solution {
public:
    // int findNumbers(vector<int> &nums)
    // {
    //     int a, res = 0;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         int a = nums[i], count = 0;
    //         while (a > 0)
    //         {
    //             count++;
    //             a = a / 10;
    //         }
    //         if ((count % 2) == 0)
    //         {
    //             res++;
    //         }
    //     }
    //     return res;
    // }

    int findNumbers(vector<int> &nums)
    {
        int cnt = 0;
        for (auto i : nums)
            if ((int)log10(i) % 2)
                ++cnt; // log10() returns no of digit -1
        return cnt;
    }
};
// @lc code=end

