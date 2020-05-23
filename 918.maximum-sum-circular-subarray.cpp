/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int min_ans2 = INT_MAX; //minimum kadane
        int max_ans1 = INT_MIN; //maximum kadane
        int curr_ans2 = INT_MAX;
        int curr_ans1 = INT_MIN;
        int sum = 0;
        for (auto &i : A)
            sum += i;
        for (auto &i : A)
        {

            curr_ans1 = i + max(curr_ans1, 0);
            max_ans1 = max(curr_ans1, max_ans1);
            curr_ans2 = i + min(curr_ans2, 0);
            min_ans2 = min(curr_ans2, min_ans2);
        }
        if (sum == min_ans2)
            return max_ans1;
        return max(max_ans1, sum - min_ans2);
    }
};
// @lc code=end
