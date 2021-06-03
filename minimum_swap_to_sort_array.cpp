/*
*    @Date    : 2021-06-03 15:43:22
*    @Author  : aerma7309 
*/


//  https://www.hackerrank.com/challenges/minimum-swaps-2/problem

#include <bits/stdc++.h>
using namespace std;

int minimumSwaps(vector<int> arr)
{
    vector<vector<int>> v;
    for (int i = 0; i < arr.size(); i++)
    {
        v.push_back({arr[i], i});
    }

    sort(v.begin(), v.end());

    int ans = 0;
    vector<bool> vis(arr.size(), false);
    for (int i = 0; i < arr.size(); i++)
    {
        if (!vis[i])
        {
            int j = i, cnt = 0;
            while (!vis[j])
            {
                vis[j] = true;
                cnt++;
                j = v[j][1];
            }
            ans += (cnt - 1);
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {4, 3, 2, 1};
    cout << minimumSwaps(v);
    return 0;
}