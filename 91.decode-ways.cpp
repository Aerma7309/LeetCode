// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem91.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution
{
public:
    map<int, int> m;
    int numDecodings(string s, int i = 0)
    {
        if (i > s.size() or s[i] == '0')
            return 0;
        if (i == s.size())
            return 1;
        if (m[i])
            return m[i];
        int ans = 0;
        ans += numDecodings(s, i + 1);
        if (i + 1 < s.size() and stoi(s.substr(i, 2)) <= 26)
            ans += numDecodings(s, i + 2);
        return m[i] = ans;
    }
};
// @lc code=end
