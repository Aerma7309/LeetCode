// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution
{
public:
    vector<string> v{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    void letterCombinationsHelper(string &digits, int i, string s)
    {
        if (i == digits.size())
        {
            res.emplace_back(s);
            return;
        }
        for (auto &c : v[(digits[i] - '0')])
            letterCombinationsHelper(digits, i + 1, s + c);
    }
    vector<string> letterCombinations(string &digits)
    {
        if (digits.empty())
            return res;
        letterCombinationsHelper(digits, 0, "");
        return res;
    }
};
// @lc code=end
