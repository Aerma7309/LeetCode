/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */
#include <bits/stdc++.h>
// @lc code=start
class StockSpanner
{
    stack<pair<int, int>> s;
    int index;

public:
    StockSpanner()
    {
        index = -1;
    }

    int next(int price)
    {
        index++;
        while (!s.empty() and s.top().first <= price)
            s.pop();
        int ans;
        if (s.empty())
        {
            s.emplace(price, index);
            ans = index + 1;
        }
        else
        {
            ans = index - s.top().second;
            s.emplace(price, index);
        }

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
