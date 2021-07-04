/*
 * @lc app=leetcode id=1497 lang=cpp
 *
 * [1497] Check If Array Pairs Are Divisible by k
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        if (arr.size() & 1)
            return false;
        unordered_map<int, int> m;
        for (auto &num : arr)
            m[(((num % k) + k) % k)]++;
        for (auto &freq : m)
            if (freq.first != 0 and freq.second != m[k - freq.first])
                return false;
        return not(m[0] & 1);
    }
};
// @lc code=end
