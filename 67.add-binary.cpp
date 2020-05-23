// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem67.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res = "";
        if (a.empty())
            return b;
        if (b.empty())
            return a;
        int len_a = a.size() - 1, len_b = b.size() - 1;
        int carry = 0;
        while (len_a >= 0 and len_b >= 0)
        {
            int sum = (a[len_a] - '0') + (b[len_b] - '0') + carry;
            res =  (char)(sum % 2 + '0') + res;
            carry = sum / 2;
            len_a--;
            len_b--;
        }
        while (len_a >= 0)
        {
            int sum = (a[len_a] - '0') + carry;
            res = (char)(sum % 2 + '0') + res;
            carry = sum / 2;
            len_a--;
        }
        while (len_b >= 0)
        {
            int sum = (b[len_b] - '0') + carry;
            res = (char)(sum % 2 + '0') + res;
            carry = sum / 2;
            len_b--;
        }
        if (carry > 0)
            res = (char)(carry + '0') + res;
        return res;
    }
};
// @lc code=end
