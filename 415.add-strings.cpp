/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int idx1 = num1.size() - 1, idx2 = num2.size() - 1, sum, carry = 0;
        string ans = "";
        while (idx1 >= 0 and idx2 >= 0)
        {
            sum = (num1[idx1--] - '0') + (num2[idx2--] - '0') + carry;
            carry = sum / 10;
            ans.push_back('0' + (sum % 10));
        }

        while (idx1 >= 0)
        {
            sum = (num1[idx1--] - '0') + carry;
            carry = sum / 10;
            ans.push_back('0' + (sum % 10));
        }

        while (idx2 >= 0)
        {
            sum = (num2[idx2--] - '0') + carry;
            carry = sum / 10;
            ans.push_back('0' + (sum % 10));
        }

        if (carry)
            ans.push_back('0' + carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
