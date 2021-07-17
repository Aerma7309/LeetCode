/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // int numJewelsInStones(string J, string S)
    // {
    //     int cnt = 0;
    //     for (char ch : J)
    //         cnt += count(S.begin(), S.end(), ch);
    //     return cnt;
    // }

    // int numJewelsInStones(string j, string s)
    // {
    //     int cnt = 0;
    //     unordered_set<char> m(j.begin(), j.end());
    //     for (auto &i : s)
    //         if (m.find(i) != m.end())
    //             cnt++;
    //     return cnt;
    // }

    int numJewelsInStones(string j, string s)
    {
        bitset<256> m;
        int cnt = 0;
        for (auto &ch : j)
            m[(int)ch] = true;
        for (auto &ch : s)
            if (m[(int)ch])
                ++cnt;
        return cnt;
    }
};
// @lc code=end
