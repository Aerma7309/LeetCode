#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /**
     * @param sticks: the length of sticks
     * @return: Minimum Cost to Connect Sticks
     */
    int MinimumCost(vector<int> &sticks)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int cost = 0;
        for (auto &stick : sticks)
            pq.push(stick);
        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a + b);
            cost += a + b;
        }
        return cost;
    }
};