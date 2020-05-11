// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem448.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
            nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                res.push_back(i + 1);
        return res;

        // int n = nums.size();
        // map<int, bool> s;
        // for (auto &i : nums)
        //     s[i] = true;
        // vector<int> v;
        // for (int i = 1; i <= n; i++)
        //     if (!s[i])
        //         v.push_back(i);
        // return v;
    }
};
// @lc code=end
