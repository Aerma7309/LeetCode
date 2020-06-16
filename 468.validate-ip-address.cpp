// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem468.h"
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=468 lang=cpp
 *
 * [468] Validate IP Address
 */

// @lc code=start
#include <cctype>
class Solution
{
public:
    string validIPAddress(string IP)
    {
        int cdot = count(IP.begin(), IP.end(), '.');
        int ccol = count(IP.begin(), IP.end(), ':');
        int cnt = 0;
        if (cdot == 3)
        {
            stringstream ss(IP);
            string num;
            for (int i = 0; i < 4; i++)
            {
                getline(ss, num, '.');
                if (num.empty() or (num.size() > 1 and num[0] == '0') or num.size() >= 4)
                    return "Neither";
                for (auto &i : num)
                    if (!(isdigit(i)))
                        return "Neither";
                if (stoi(num) > 255)
                    return "Neither";
            }
            return "IPv4";
        }
        else if (ccol == 7)
        {

            stringstream ss(IP);
            string num;
            for (int i = 0; i < 8; i++)
            {
                getline(ss, num, ':');
                if (num.empty() or num.size() > 4)
                    return "Neither";
                for (auto &i : num)
                    if (!(isalnum(i)) or (isalpha(i) and tolower(i) > 'f'))
                        return "Neither";
            }
            return "IPv6";
        }
        return "Neither";
    }
};
// @lc code=end
