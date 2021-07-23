/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // int dominantIndex(vector<int> &nums)
    // {
    //     if (nums.size() == 1)
    //         return 0;
    //     int fl = -1, sl = -1;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (fl == -1 or sl == -1)
    //         {
    //             if (fl == -1)
    //                 fl = i;
    //             else if (nums[fl] < nums[i])
    //             {
    //                 sl = fl;
    //                 fl = i;
    //             }
    //             else
    //                 sl = i;
    //         }
    //         else if (nums[fl] < nums[i])
    //         {
    //             sl = fl;
    //             fl = i;
    //         }
    //         else if (nums[sl] < nums[i])
    //             sl = i;
    //     }
    //     if (nums[fl] >= 2 * nums[sl])
    //         return fl;
    //     return -1;
    // }

    int dominantIndex(vector<int> &nums)
    {
        int mx = 0; //index of maximum element
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] > nums[mx])
                mx = i;
        // check if every no is twice smaller
        for (int i = 0; i < nums.size(); i++)
            if (i != mx and nums[i] > nums[mx] / 2)
                return -1;
        return mx;
    }
};
// @lc code=end
