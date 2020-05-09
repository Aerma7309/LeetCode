/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
class Solution
{
public:
    // void duplicateZeros(vector<int>& arr) {
    // int s = arr.size();
    // for(int i =0; i<s; i++)
    // {
    //     if(arr[i]==0)
    //     {
    //         i++;
    //         for(int j=s-1; j>=i;j--)
    //         arr[j]=arr[j-1];
    //     }
    // }
    // }

    void duplicateZeros(vector<int> &arr)
    {
        int s = arr.size();
        int z = count(arr.begin(), arr.end(), 0);
        arr.resize(s + z);
        for (int i = s - 1, j = s + z - 1; i >= 0; i--)
        {
            if (arr[i] == 0)
                arr[j] = 0, arr[j - 1] = 0, j -= 2;
            else
                arr[j] = arr[i], j -= 1;
        }
        arr.resize(s);
    }
};
// @lc code=end
