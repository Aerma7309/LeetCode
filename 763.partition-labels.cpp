// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem763.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        map<char, int> m;
        vector<int> res;
        for (int i = 0; i < s.size(); i++)
            m[s[i]] = i;
        int a = 0, b = 0, c = 0;
        for (; c < (int)s.size();)
        {
            while (b <= c)
                c = max(c, m[s[b++]]);
            res.push_back(c - a + 1);
            a = b = c = c + 1;
        }
        return res;
    }
};
// @lc code=end
