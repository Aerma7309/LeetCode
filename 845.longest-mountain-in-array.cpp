/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        if (arr.size() < 3)
            return 0;
        int max_length = 0, right = 1;

        for (; right < arr.size() - 1;)
        {
            if (arr[right] > arr[right - 1] and arr[right] > arr[right + 1])
            {
                int left = right - 1;
                while (left > 0 and arr[left] > arr[left - 1])
                    left--;
                while (right < arr.size() - 1 and arr[right + 1] < arr[right])
                    right++;
                max_length = max(max_length, right - left + 1);
            }
            right++;
        }
        return max_length;
    }
};
// @lc code=end
