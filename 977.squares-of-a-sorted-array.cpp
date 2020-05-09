/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution
{
public:
    // vector<int> sortedSquares(vector<int>& A) {
    //     vector<int> res;
    //     res.reserve(A.size());
    //     for(int &i: A) res.push_back(i*i);
    //     sort(res.begin(),res.end());
    //     return res;
    // }

    vector<int> sortedSquares(vector<int> &A)
    {
        int size = A.size();
        int lb = 0, ub = size - 1, mid, res = 0;
        // res = upper_bound(A.begin(),A.end(),-1)-A.begin();
        while (lb <= ub)
        {
            mid = (lb + ub) / 2;
            if (A[mid] > -1)
                ub = mid - 1, res = mid;
            else
                lb = mid + 1;
        }
        int i = res - 1, j = res;
        vector<int> R;
        R.reserve(size);
        while (i >= 0 and j < size)
        {
            if (-A[i] < A[j])
                R.push_back(A[i] * A[i]), --i;
            else
                R.push_back(A[j] * A[j]), ++j;
        }
        while (i >= 0)
            R.push_back(A[i] * A[i]), --i;
        while (j < size)
            R.push_back(A[j] * A[j]), ++j;
        return R;
    }
};
// @lc code=end
