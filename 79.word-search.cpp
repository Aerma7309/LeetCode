/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
int FastIO = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    bool existHelper(vector<vector<char>> &board, string word, int curr, int i, int j)
    {
        if (word.size() == curr)
            return true;
        if (i < 0 or j < 0 or i >= board.size() or j >= board[0].size())
            return false;
        if (board[i][j] != word[curr])
            return false;
        char save = board[i][j];
        board[i][j] = ' ';
        bool res = false;
        res |= existHelper(board, word, curr + 1, i - 1, j);
        res |= existHelper(board, word, curr + 1, i + 1, j);
        res |= existHelper(board, word, curr + 1, i, j - 1);
        res |= existHelper(board, word, curr + 1, i, j + 1);
        board[i][j] = save;
        return res;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (existHelper(board, word, 0, i, j))
                    return true;
        return false;
    }
};
// @lc code=end
