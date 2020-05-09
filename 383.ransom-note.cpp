/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> m;
        for (char &i : magazine)
            m[i]++;
        // for (char &i : ransomNote)
        //     rn[i]++;
        for (auto i : ransomNote)
            if (m[i])
                m[i]--;
            else
                return false;
        return true;
    }
};
// @lc code=end

