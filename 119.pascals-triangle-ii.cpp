// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem119.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        //row index starts from zero 
        vector<int> prev;
        for (int i = 1; i <= rowIndex+1; i++)
        {
            vector<int> curr(prev.size() + 1);
            curr[0]=1;
            for (int i = 1; i < prev.size(); i++)
                curr[i] = prev[i] + prev[i - 1];
            if (i > 1)
                curr[prev.size()]=1;
            prev = curr;
        }
        return prev;
    }
};
// @lc code=end
