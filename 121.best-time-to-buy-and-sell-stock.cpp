/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mx = prices.back(), profit = 0;
        for (int i = prices.size() - 2; i >= 0; i--)
            profit = max(profit, mx - prices[i]), mx = max(mx, prices[i]);
        return profit;
    }
};
// @lc code=end
