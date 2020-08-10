/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
int FastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() < 2)
            return;

        int left, right;

        for (left = nums.size() - 2; left >= 0; left--)
            if (nums[left] < nums[left + 1])
                break;
        if (left < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (right = nums.size() - 1; right > left; right--)
                if (nums[right] > nums[left])
                    break;
            swap(nums[left], nums[right]);
            reverse(nums.begin() + left + 1, nums.end());
        }
    }
};
// @lc code=end
