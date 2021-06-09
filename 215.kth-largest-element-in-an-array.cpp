/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int partition(vector<int> &nums, int start, int end)
    {
        int pivot = nums[start];
        int i = start, j = start + 1;
        for (; j <= end; j++)
        {
            if (nums[j] > pivot)
                swap(nums[++i], nums[j]);
        }
        swap(nums[i], nums[start]);
        return i;
    }
    int quick_select(vector<int> &nums, int k, int start, int end)
    {
        int par = partition(nums, start, end);
        if (par == k)
            return nums[par];
        else if (k < par)
            return quick_select(nums, k, start, par - 1);
        return quick_select(nums, k, par + 1, end);
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        return quick_select(nums, k - 1, 0, nums.size() - 1);
    }
};
// @lc code=end
