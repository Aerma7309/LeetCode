/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

class Solution
{

public:
    int compress(vector<char> &chars)
    {
        int inp = 0, left = 0, right, n = chars.size();
        for (; left < n;)
        {
            for (right = left + 1; right < n and chars[left] == chars[right]; right++)
                ;
            int cnt = right - left;
            chars[inp++] = chars[left];
            if (cnt > 1)
            {
                for (auto &ch : to_string(cnt))
                    chars[inp++] = ch;
            }
            left = right;
        }
        if (n > inp)
            chars.erase(chars.begin() + inp, chars.end());
        return chars.size();
    }
};
// @lc code=end
