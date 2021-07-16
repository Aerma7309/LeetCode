/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        // int s = nums.size();
        // int c = count(nums.begin(), nums.end(), val);
        // for (int i = 0, j = s - 1; i < s - c; i++)
        // {
        //     if (nums[i] == val)
        //     {
        //         while (nums[j] == val)
        //             j--;
        //         swap(nums[i], nums[j]);
        //     }
        // }
        // return s - c;

        int n = nums.size(), i, j;
        for (i = 0, j = 0; j < n; j++)
        {
            if (nums[j] == val)
                continue;
            nums[i] = nums[j];
            i++;
        }
        return i;
    }
};
// @lc code=end
