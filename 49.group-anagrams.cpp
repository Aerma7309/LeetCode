/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        map<string, vector<string>> m;
        for (auto &i : strs)
        {
            string s = i;
            sort(s.begin(), s.end());
            m[s].emplace_back(i);
        }
        for (auto &i : m)
            res.emplace_back(i.second);
        return res;
    }

    // vector<vector<string>> groupAnagrams(vector<string> &strs)
    // {
    //     vector<vector<string>> res;
    //     map<map<char, int>, vector<string>> m;
    //     for (auto &i : strs)
    //     {
    //         map<char, int> tm;
    //         for (auto &ch : i)
    //             tm[ch]++;
    //         m[tm].emplace_back(i);
    //     }
    //     for (auto &i : m)
    //         res.emplace_back(i.second);
    //     return res;
    // }
};
// @lc code=end
