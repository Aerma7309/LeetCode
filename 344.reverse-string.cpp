/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution
{
public:
    // void reverseString(vector<char> &s)
    // {
    //     for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    //         swap(s[i], s[j]);
    // }

    void reverse_helper(vector<char> &s, int l, int r)
    {
        if (l >= r)
            return;
        swap(s[l], s[r]);
        reverse_helper(s, l + 1, r - 1);
    }

    void reverseString(vector<char> &s, int i = 0)
    {
        reverse_helper(s, 0, s.size()-1);
    }
};
// @lc code=end
