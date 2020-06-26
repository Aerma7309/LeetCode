/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int size = citations.size();
        if (size == 0)
            return size;
        int lb = 0, ub = *max_element(citations.begin(), citations.end()), mid;
        auto check = [&](int i) {
            int left = lower_bound(citations.begin(), citations.end(), i) - citations.begin();
            int right = size - left;
            return right >= i;
        };
        while (lb < ub)
        {
            mid = lb + (ub - lb) / 2 + 1;
            if (check(mid))
                lb = mid;
            else
                ub = mid - 1;
        }
        return lb;
    }
};
// @lc code=end
