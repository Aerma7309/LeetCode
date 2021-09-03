/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        int n = columnNumber;
        while (n)
        {
            ans.push_back('A'+((n-1)%26));
            n = (n-1)/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

