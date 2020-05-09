/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
class Solution {
public:
    // bool checkIfExist(vector<int>& arr) {
    //     for(int i=0;i<arr.size();i++)
    //      for(int j=i+1;j<arr.size();j++) if(arr[j]==(2*arr[i]) or arr[i]==(2*arr[j])) return true;
    //     return false;
    // }

    bool checkIfExist(vector<int> &arr)
    {
        map<int, bool> m;
        for (auto &i : arr)
            if (m[2 * i] or (i % 2 == 0 and m[i / 2]))
                return true;
            else
                m[i] = 1;
        return false;
    }
};
// @lc code=end

