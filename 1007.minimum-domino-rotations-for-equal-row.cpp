/*
 * @lc app=leetcode id=1007 lang=cpp
 *
 * [1007] Minimum Domino Rotations For Equal Row
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int n = tops.size(), ans = INT_MAX;
        vector<int> v = {tops[0], bottoms[0]};
        // for (int i = 1; i <= 6; i++)
        for (auto &i : v)
        {
            int tc = 0, bc = 0;
            for (int t = 0; t < n; t++)
            {
                if (tops[t] == i)
                    continue;
                else if (bottoms[t] == i)
                    tc++;
                else
                {
                    tc = INT_MAX;
                    break;
                }
            }
            for (int b = 0; b < n; b++)
            {
                if (bottoms[b] == i)
                    continue;
                else if (tops[b] == i)
                    bc++;
                else
                {
                    bc = INT_MAX;
                    break;
                }
            }
            ans = min({ans, tc, bc});
        }
        return ans != INT_MAX ? ans : -1;
    }
};
// @lc code=end
