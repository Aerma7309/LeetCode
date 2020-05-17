/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> vs;
        string temp;
        while (iss >> temp)
            vs.push_back(temp);
        if (vs.empty())
            return "";
        for (auto &i : vs)
            reverse(i.begin(), i.end());
        ostringstream oss;
        for (int i = 0; i < vs.size() - 1; i++)
            oss << vs[i] << " ";
        oss << vs.back();
        return oss.str();
    }
};
// @lc code=end

