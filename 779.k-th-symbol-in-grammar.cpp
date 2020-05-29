/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

// @lc code=start
class Solution
{
public:
    // int kthGrammar(int N, int K)
    // {
    //     if(N==1) return 0;
    //     if(K%2==0) return kthGrammar(N-1,K/2)==0?1:0;
    //     return kthGrammar(N - 1, (K+1) / 2);
    // }

    int kthGrammar(int N, int K)
    {
        return __builtin_popcount(K-1)%2;
    }
};
// @lc code=end
