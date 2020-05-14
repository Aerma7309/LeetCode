// @before-stub-for-debug-begin
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include "commoncppproblem997.h"
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        /**
         * int[0] trusted count
         * int[1] trustee count
         * */
        if (N == 1 and trust.empty())
            return 1;
        map<int, int[2]> frequency;
        for (auto &i : trust)
            frequency[i[0]][0]++, frequency[i[1]][1]++;
        for (auto &i : frequency)
        {
            if ((i.second[0] == 0 and i.second[1] == N - 1))
                return i.first;
        }
        return -1;
    }
};
// @lc code=end
