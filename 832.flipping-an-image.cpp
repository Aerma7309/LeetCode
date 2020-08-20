/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
int FastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        for (auto &i : A)
        {
            reverse(i.begin(), i.end());
            for_each(i.begin(), i.end(), [](auto &a) { (a == 1) ? a = 0 : a = 1; });
        }
        return A;
    }
};
// @lc code=end
