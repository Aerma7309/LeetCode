// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem59.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> m(n, vector<int>(n));
        int rs = 0, re = n, cs = 0, ce = n, k = 1;
        while (rs < re and cs < ce)
        {
            for (int col = cs; col < ce; col++)
                m[rs][col] = k++;
            rs++;
            for (int row = rs; row < re; row++)
                m[row][ce - 1] = k++;
            ce--;
            for (int col = ce - 1; col >= cs; col--)
                m[re - 1][col] = k++;
            re--;
            for (int row = re - 1; row >= rs; row--)
                m[row][cs] = k++;
            cs++;
        }
        return m;
    }
};
// @lc code=end
