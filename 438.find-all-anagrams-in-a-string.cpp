// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem438.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int f[26] = {0}, p_size = p.size(), cnt = 0;
        for (auto &i : p)
            f[i - 'a']++;
        vector<int> r;
        auto fun = [&](int i) {
            for (int x = 0; x < 26; x++)
                if (f[x] != 0)
                    return;
            r.push_back(i - p_size + 1);
        };

        for (int i = 0; i < s.size(); i++)
        {
            if (i < p.size())
            {
                f[s[i] - 'a']--;
                fun(i);
            }
            else
            {
                f[s[i] - 'a']--;
                f[s[i - p_size] - 'a']++;
                fun(i);
            }
        }
        return r;
    }
};
// @lc code=end
