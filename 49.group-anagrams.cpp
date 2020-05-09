/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<pair<string, int>> copy;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++)
            copy.push_back(make_pair(strs[i], i));

        for (auto &s : copy)
        {
            sort(s.first.begin(), s.first.end(), [](auto a, auto b) { return a < b; });
        }
        sort(copy.begin(), copy.end());

        auto iter = copy.begin();
        while (iter != copy.end())
        {

            vector<string> tmp;
            tmp.push_back(strs[iter->second]);
            auto it = iter + 1;
            while (it != copy.end() and (it->first == iter->first))
            {
                tmp.push_back(strs[it->second]);
                it++;
            }
            iter = it;
            res.push_back(tmp);
        }
        sort(res.begin(), res.end(), [](vector<string> &a, vector<string> &b) { return a.size() < b.size(); });
        for (auto &i : res)
        {
            sort(i.begin(), i.end());
        }
        return res;
    }
};
// @lc code=end

