/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{

public:
    bool isInterleave(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &cache)
    {

        if (i == s1.size())
            return s2.substr(j) == s3.substr(k);
        if (j == s2.size())
            return s1.substr(i) == s3.substr(k);
        if (cache[i][j] != -1)
            return cache[i][j];
        bool result = false;
        if (s1[i] == s3[k])
            result |= isInterleave(s1, s2, s3, i + 1, j, k + 1, cache);
        if (s2[j] == s3[k])
            result |= isInterleave(s1, s2, s3, i, j + 1, k + 1, cache);
        cache[i][j] = result;
        return result;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<int>> cache(s1.size(), vector<int>(s2.size(), -1));
        return isInterleave(s1, s2, s3, 0, 0, 0, cache);
    }
};
// @lc code=end
