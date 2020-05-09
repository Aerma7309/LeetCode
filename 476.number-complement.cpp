/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num)
    {
        int res = 0;
        bool flag = true;
        for (int i = 30; i >= 0; i--)
        {
            if (flag and (num >> i))
                flag = false;
            if (!flag)
                res += (1 << i) & (~num);
        }
        return res;
    }

    //      int findComplement(int num) {
    //         int i = 0,n=num;
    //         for(i=30; i>=0;i--)
    //             if(num>>i) break;
    //
};
// @lc code=end

