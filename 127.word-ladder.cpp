/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // Single Direction Search
    // int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    // {
    //     unordered_set<string> words(wordList.begin(), wordList.end());
    //     if (words.find(endWord) == words.end())
    //         return 0;
    //     int depth = 0;
    //     queue<string> q;
    //     q.push(beginWord);
    //     while (not q.empty())
    //     {
    //         int size = q.size();
    //         for (int i = 0; i < size; i++)
    //         {
    //             string curr = q.front();
    //             q.pop();
    //             words.erase(curr);
    //             if (curr == endWord)
    //                 return depth + 1;
    //             for (int sz = 0; sz < curr.size(); sz++)
    //             {
    //                 for (int ch = 'a'; ch <= 'z'; ch++)
    //                 {
    //                     if (ch == curr[sz])
    //                         continue;
    //                     string nxt = curr;
    //                     nxt[sz] = ch;
    //                     if (words.find(nxt) != words.end())
    //                         q.push(nxt);
    //                 }
    //             }
    //         }
    //         depth++;
    //     }
    //     return 0;
    // }

    // using BiDirectional Search

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end())
            return 0;
        int depth = 0;
        bool turn = 0;
        queue<string> q[2];
        set<string> vis[2];
        q[turn].push(beginWord);
        q[not turn].push(endWord);
        while (not q[turn].empty())
        {
            int size = q[turn].size();
            for (int i = 0; i < size; i++)
            {
                string curr = q[turn].front();
                q[turn].pop();
                words.erase(curr);
                vis[turn].insert(curr);
                if (vis[not turn].find(curr) != vis[not turn].end())
                    return depth;
                for (int sz = 0; sz < curr.size(); sz++)
                {
                    for (int ch = 'a'; ch <= 'z'; ch++)
                    {
                        if (ch == curr[sz])
                            continue;
                        string nxt = curr;
                        nxt[sz] = ch;
                        if (words.find(nxt) != words.end())
                            q[turn].push(nxt);
                    }
                }
            }
            depth++;
            turn = not turn;
        }
        return 0;
    }
};
// @lc code=end
