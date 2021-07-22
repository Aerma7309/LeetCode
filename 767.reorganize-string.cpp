/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // string reorganizeString(string s)
    // {
    //     map<char, int> freq;
    //     for (auto &ch : s)
    //         freq[ch]++;

    //     auto compare = [&](char a, char b)
    //     { return freq[a] < freq[b]; };

    //     priority_queue<char, vector<char>, decltype(compare)> pq(compare);
    //     for (auto &it : freq)
    //         pq.push(it.first);

    //     string ans = "";
    //     while (pq.size() > 1) // if only one char it can repeat
    //     {
    //         char first = pq.top();
    //         pq.pop();
    //         char second = pq.top();
    //         pq.pop();
    //         ans.push_back(first);
    //         ans.push_back(second);
    //         freq[first]--;
    //         freq[second]--;
    //         if (freq[first])
    //             pq.push(first);
    //         if (freq[second])
    //             pq.push(second);
    //     }
    //     if (not pq.empty() and freq[pq.top()] > 1) // if char is repeating
    //         return "";
    //     if (not pq.empty()) //adding last char
    //         ans.push_back(pq.top());
    //     return ans;
    // }

    string reorganizeString(string S)
    {
        vector<int> cnt(26);
        int mostFreq = 0, i = 0;

        for (char c : S)
            if (++cnt[c - 'a'] > cnt[mostFreq])
                mostFreq = (c - 'a');

        // if not possible to make a string when most frequent character does not satisfy above condition, return empty string
        if (2 * cnt[mostFreq] - 1 > S.size())
            return "";
            
        // populate the most frequent char at alternate places starting from the index 0(even indexes), eg: 0,2,4,6 .....
        while (cnt[mostFreq])
        {
            S[i] = ('a' + mostFreq);
            i += 2;
            cnt[mostFreq]--;
        }

        // start populating the other characters with a gap of 1 index, from where the most frequent element got exhausted(continue for even indexes).
        // if we reach the end of the string size in this process, then start populating for odd indexes starting from 1 and continue with a gap of 1, eg: 1,3,5,7......
        for (int j = 0; j < 26; j++)
        {
            while (cnt[j])
            {
                if (i >= S.size())
                    i = 1;
                S[i] = ('a' + j);
                cnt[j]--;
                i += 2;
            }
        }

        return S;
    }
};
// @lc code=end
