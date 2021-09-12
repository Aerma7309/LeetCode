/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (!prices.size())
            return 0;
        int buy1 = INT_MAX;
        int profit1 = INT_MIN;
        int buy2 = INT_MAX;
        int profit2 = INT_MIN;
        for (auto &price : prices)
        {
            buy1 = min(price, buy1);
            profit1 = max(profit1, price - buy1);
            buy2 = min(buy2, price - profit1);
            profit2 = max(profit2, price - buy2);
        }
        return profit2;
    }
};
// @lc code=end
