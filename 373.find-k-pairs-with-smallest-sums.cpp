/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    struct comparator
    {
        bool operator()(array<long long, 4> &a, array<long long, 4> &b)
        {
            return a[0] + a[1] > b[0] + b[1];
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int l1 = nums1.size(), l2 = nums2.size();
        // priority element num1,num2,idx1,idx2
        priority_queue<array<long long, 4>, vector<array<long long, 4>>, comparator> q;
        for (int i = 0; i < l1; i++)
            q.push({nums1[i], nums2[0], i, 0});
        vector<vector<int>> res;
        while (not q.empty() and k > 0)
        {
            array<long long, 4> temp = q.top();
            q.pop();
            k--;
            res.push_back({(int)temp[0], (int)temp[1]});
            if (temp[3] + 1 < l2)
                q.push({nums1[temp[2]], nums2[temp[3] + 1], temp[2], temp[3] + 1});
        }
        return res;
    }
};
// @lc code=end
