/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> *oldList = new vector<int>{0, 1}, *newList = nullptr;
        for (int i = 1; i < n; i++)
        {
            newList = new vector<int>(oldList->begin(), oldList->end());
            for (int j = oldList->size() - 1; j >= 0; j--)
                newList->push_back((1 << i) | oldList->operator[](j));
            delete oldList;
            oldList = newList;
        }
        return *oldList;
    }
};
// @lc code=end
