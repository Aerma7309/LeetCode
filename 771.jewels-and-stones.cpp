/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string J, string S)
    {
        int cnt = 0;
        for (char ch : J)
            cnt += count(S.begin(), S.end(), ch);
        return cnt;
    }
};
// @lc code=end

