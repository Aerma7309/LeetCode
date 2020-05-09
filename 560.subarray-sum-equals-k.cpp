/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int> &nums, int k)
    {
        map<int, int> f;
        f[0] = 1;
        int sum = 0, cnt = 0;
        for (int i : nums)
        {
            sum += i;
            cnt += f[sum - k];
            f[sum]++;
        }
        return cnt;
    }
};
// @lc code=end

