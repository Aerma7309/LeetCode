/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        set<string> s;
        for (auto &id : emails)
        {
            string currId = "";
            int idx = id.find('@');
            for (auto &ch : id)
            {
                if (ch == '+' or ch == '@')
                    break;
                else if (ch != '.')
                    currId.push_back(ch);
            }
            if (idx == -1)
                continue;
            s.insert(currId + id.substr(idx));
        }
        return s.size();
    }
};
// @lc code=end
