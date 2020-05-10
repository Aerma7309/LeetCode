/*
 * @lc app=leetcode id=1442 lang=cpp
 *
 * [1442] Count Triplets That Can Form Two Arrays of Equal XOR
 */

// @lc code=start
class Solution {
public:
    int countTriplets(vector<int> &arr)
    {
        int size = arr.size();
        for (int i = 1; i < size; i++)
            arr[i] = arr[i] ^ arr[i - 1];
        int count = 0;
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                for (int k = j; k < size; k++)
                {
                    if (i == 0)
                    {
                        if (arr[j - 1] == (arr[j - 1] ^ arr[k]))
                            count += 1;
                    }
                    else
                    {
                        if ((arr[i - 1] ^ arr[j - 1]) == (arr[j - 1] ^ arr[k]))
                            count += 1;
                    }
                }
        return count;
    }
};
// @lc code=end

