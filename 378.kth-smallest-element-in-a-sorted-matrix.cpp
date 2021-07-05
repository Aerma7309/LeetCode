// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem378.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

class Solution
{
public:
    // O(n*nlogk)
    // int kthSmallest(vector<vector<int>> &matrix, int k)
    // {
    //     priority_queue<int> q;
    //     for (auto &row : matrix)
    //         for (auto &num : row)
    //         {
    //             q.push(num);
    //             if (q.size() > k)
    //                 q.pop();
    //         }
    //     return q.top();
    // }

    //  O(n+klogn)
    // struct heap_comparator
    // {
    //     bool operator()(array<int, 3> &a, array<int, 3> &b)
    //     {
    //         return a[0] > b[0];
    //     }
    // };
    // int kthSmallest(vector<vector<int>> &matrix, int k)
    // {
    //     int n = matrix.size();
    //     priority_queue<array<int, 3>, vector<array<int, 3>>, heap_comparator> pq;
    //     for (int i = 0; i < n; i++)
    //         pq.push({matrix[i][0], i, 0});
    //     int cnt = 1;
    //     while (not pq.empty() and cnt < k)
    //     {
    //         auto temp = pq.top();
    //         pq.pop();
    //         if (temp[2] + 1 < n)
    //             pq.push({matrix[temp[1]][temp[2] + 1], temp[1], temp[2] + 1});
    //         cnt++;
    //     }
    //     return pq.top()[0];
    // }

    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int lb = matrix[0][0], ub = matrix[n - 1][n - 1];
        while (lb < ub)
        {
            int mid = lb + (ub - lb) / 2, cnt = 0;
            for (int i = 0; i < n; i++)
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if (cnt >= k)
                ub = mid;
            else
                lb = mid + 1;
        }
        return lb;
    }
};
// @lc code=end
