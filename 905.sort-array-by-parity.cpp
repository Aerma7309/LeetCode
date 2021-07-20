/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // vector<int> sortArrayByParity(vector<int>& A) {
    //     auto l = A.begin();
    //     auto r = --A.end();
    //     while (distance(l,r)>0)
    //     {
    //         if(*l%2==1 and *r%2==0) swap(*l,*r);
    //         else if(*l%2==0) l++;
    //         else r--;
    //     }
    //     return A;
    // }

    vector<int> sortArrayByParity(vector<int> &A)
    {
        int idx = -1;
        for (int i = 0; i < A.size(); i++)
            if (not(A[i] & 1))
                swap(A[++idx], A[i]);
        return A;
    }
};
// @lc code=end
