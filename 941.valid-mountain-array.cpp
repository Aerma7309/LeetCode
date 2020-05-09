/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
class Solution
{
public:
    bool validMountainArray(vector<int> &A)
    {
        bool inc = true;
        int s = A.size(), prev = -1;
        if (s < 3)
            return false;
        // for(int i=0;i<s-1;i++)
        // {
        //     if(inc and A[i]>prev) prev=A[i];
        //     else if(A[i] <prev) prev=A[i],inc=false;
        //     else return false;
        // }
        for (auto &i : A)
        {
            if (inc and i > prev)
                prev = i;
            else if (i < prev)
                prev = i, inc = false;
            else
                return false;
        }
        if (!(A[1] > A[0] and A[s - 1] < A[s - 2]))
            return false;
        return true;
    }
};
// @lc code=end
