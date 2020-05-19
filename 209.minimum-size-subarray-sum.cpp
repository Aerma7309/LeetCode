/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int sum = 0;
        for (auto &i : nums)
        {
            i = sum + i;
            sum = i;
        }
        int ans = INT_MAX;
        auto getSum = [&](int i, int j) -> int {
            if (i == 0)
                return nums[j];
            return nums[j] - nums[i - 1];
        };
        for (int i = 0, j = 0; j < nums.size(); j++)
        {
            while (getSum(i, j) >= s)
            {
                ans = min(ans, j - i + 1);
                i++;
            }
        }
        if (ans == INT_MAX)
            return 0;
        return ans;
    }

    // nlogn solution
    // bool isPossible(vector<int> v, int size, int k)
    // {
    //     int sum = 0;
    //     for (int i = 0; i < size; i++)
    //         sum += v[i];
    //     if (sum >= k)
    //         return true;
    //     for (int i = size; i < v.size(); i++)
    //     {
    //         sum = sum + v[i] - v[i - size];
    //         if (sum >= k)
    //             return true;
    //     }
    //     return false;
    // }
    // int minSubArrayLen(int s, vector<int> &nums)
    // {
    //     int lb = 1, ub = nums.size(), mid, res = INT_MAX;
    //     while (lb <= ub)
    //     {
    //         mid = (lb + ub) / 2;
    //         if (isPossible(nums, mid, s))
    //         {
    //             res = min(res, mid);
    //             ub = mid - 1;
    //         }
    //         else
    //             lb = mid + 1;
    //     }
    //     if (res == INT_MAX)
    //         return 0;
    //     return res;
    // }
};
// @lc code=end
