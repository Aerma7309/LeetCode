/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](int a, int b)
             { return to_string(a).append(to_string(b)) > to_string(b).append(to_string(a)); });
        stringstream ss;
        for (auto &num : nums)
            ss << num;
        string res = ss.str();
        int i = 0;
        for (; i < res.size() - 1 and res[i] == '0'; i++)
            ;
        res = res.substr(i);
        return res;
    }
};
// @lc code=end
