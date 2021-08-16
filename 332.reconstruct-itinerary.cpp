/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{

    void resolveDependency(map<string, multiset<string>> &g, vector<string> &ans, string city)
    {
        while (not g[city].empty())
        {
            string newCity = *g[city].begin();
            g[city].erase(g[city].begin());
            resolveDependency(g, ans, newCity);
        }
        ans.push_back(city);
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        map<string, multiset<string>> g;
        for (auto &ticket : tickets)
            g[ticket[0]].insert(ticket[1]);
        vector<string> ans;
        resolveDependency(g, ans, "JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
