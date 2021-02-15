// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem4.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int n = (n1 + n2 + 1) / 2, lo = 0, hi = n1;
        while (lo <= hi)
        {
            int cut1 = lo + (hi - lo) / 2;
            int cut2 = n - cut1;
            int l1 = cut1 == 0 ? numeric_limits<int>().min() : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? numeric_limits<int>().min() : nums2[cut2 - 1];
            int r1 = cut1 == n1 ? numeric_limits<int>().max() : nums1[cut1];
            int r2 = cut2 == n2 ? numeric_limits<int>().max() : nums2[cut2];

            if (l1 > r2)
                hi = cut1 - 1;
            else if (l2 > r1)
                lo = cut1 + 1;
            else
                return ((n1 + n2) & 1) ? max(l1, l2) : (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        return 0;
    }
};
// @lc code=end
