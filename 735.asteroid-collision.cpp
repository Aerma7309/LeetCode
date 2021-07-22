// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem735.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> s;
        for (auto &mag : asteroids)
        {
            if (mag > 0)
                s.push_back(mag);
            else
            {
                while (not s.empty() and s.back() > 0 and s.back() < abs(mag))
                    s.pop_back();
                if (not s.empty())
                {
                    if (s.back() + mag == 0)
                        s.pop_back();
                    else if (s.back() < 0)
                        s.push_back(mag);
                }
                else
                    s.push_back(mag);
            }
        }
        return s;
    }
};
// @lc code=end
