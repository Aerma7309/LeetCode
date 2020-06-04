// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem912.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums, int s, int mid, int e)
    {
        vector<int> v(e - s + 1);
        int i = s, j = mid + 1, k = 0;
        while (i <= mid and j <= e)
            if (nums[i] < nums[j])
                v[k++] = nums[i++];
            else
                v[k++] = nums[j++];
        while (i <= mid)
            v[k++] = nums[i++];
        while (j <= e)
            v[k++] = nums[j++];
        for (int x = 0; x < v.size(); x++)
            nums[s + x] = v[x];
    }

    void mergeSort(vector<int> &nums, int s, int e)
    {
        if (s >= e)
            return;
        int splitIndex = (s + e) / 2;
        mergeSort(nums, s, splitIndex);
        mergeSort(nums, splitIndex + 1, e);
        merge(nums, s, splitIndex, e);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end
