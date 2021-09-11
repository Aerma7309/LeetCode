/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    map<int, string> result;
    Solution()
    {
        result[1] = "1";
        for (int i = 2; i <= 30; i++)
        {
            string old = result[i - 1];
            stringstream ss;
            int a, b;
            for (a = 0; a < old.size(); a = b)
            {
                for (b = a + 1; b < old.size() and old[a] == old[b]; b++)
                    ;
                ss << b - a << old[a];
            }
            result[i]=ss.str();
        }
    }
    string countAndSay(int n)
    {
        return result[n];
    }
};
// @lc code=end
