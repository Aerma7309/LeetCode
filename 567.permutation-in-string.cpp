// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem567.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string p, string s)
    {
        int f[26] = {0}, p_size = p.size();
        for (auto &i : p)
            f[i - 'a']++;
        int i; //index of string s
        auto fun = [&]() -> bool {
            for (int x = 0; x < 26; x++)
                if (f[x] != 0)
                    return false;
            return true;
        };
        for (i = 0; i < s.size(); i++)
        {
            if (i < p.size())
            {
                f[s[i] - 'a']--;
                if (fun())
                    return true;
            }
            else
            {
                f[s[i] - 'a']--;
                f[s[i - p_size] - 'a']++;
                if (fun())
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
