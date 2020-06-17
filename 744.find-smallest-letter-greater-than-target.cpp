/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        if (it == letters.end())
            return letters[0];
        return *it;
    }
};
// @lc code=end
