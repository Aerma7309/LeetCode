/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i, j;
        for (i = 0, j = numbers.size() - 1; i < j;)
        {
            if (numbers[i] + numbers[j] == target)
                break;
            else if (numbers[i] + numbers[j] > target)
                j--;
            else
                i++;
        }
        return vector<int>{i + 1, j + 1}; // used as initializer list
    }
};
// @lc code=end
