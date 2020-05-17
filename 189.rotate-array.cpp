/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution
{
public:
    // void rotate(vector<int> &nums, int k)
    // {
    //     int size = nums.size();
    //     if (size==0 or k % size == 0)
    //         return;
    //     k = k % size;
    //     nums.resize(size+k);
    //     for (int i = size-1; i >= 0; i--)
    //         nums[i+k] = nums[i];
    //     for (int i = 0; i < k; i++)
    //         nums[i] = nums[i + size];
    //     nums.resize(size);
    // }

    void rotate(vector<int> &nums, int k)
    {
        if (nums.empty() or k % nums.size() == 0)
            return;
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end
