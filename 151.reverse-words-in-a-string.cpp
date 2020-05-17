// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem151.h"
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        
        istringstream iss(s);
        vector<string> vs;
        string temp;
        while (iss >> temp)
            vs.push_back(temp);
        if (vs.empty())
            return "";
        reverse(vs.begin(), vs.end());
        ostringstream oss;
        for (int i = 0; i < vs.size() - 1; i++)
            oss << vs[i] << " ";
        oss << vs.back();
        return  oss.str();
    }
};
// @lc code=end
