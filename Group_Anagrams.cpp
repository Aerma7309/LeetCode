/*
* @Date    : 2020-04-07 11:05:56
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
* @Link    : fb.com/aerma7309
*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<pair<string, int>> copy;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++)
            copy.push_back(make_pair(strs[i], i));

        for (auto &s : copy)
        {
            sort(s.first.begin(), s.first.end(), [](auto a, auto b) { return a < b; });
        }
        sort(copy.begin(), copy.end());

        auto iter = copy.begin();
        while (iter != copy.end())
        {

            vector<string> tmp;
            tmp.push_back(strs[iter->second]);
            auto it = iter + 1;
            while (it != copy.end() and (it->first == iter->first))
            {
                tmp.push_back(strs[it->second]);
                it++;
            }
            iter = it;
            res.push_back(tmp);
        }
        sort(res.begin(), res.end(), [](vector<string> &a, vector<string> &b) { return a.size() < b.size(); });
        for (auto &i : res)
        {
            sort(i.begin(), i.end());
        }
        return res;
    }
};

int main()
{
    vector<string> v;
    string s;
    for (int i = 0; i < 6; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    Solution solve;
    vector<vector<string>> r = solve.groupAnagrams(v);
    for (auto &i : r)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}




