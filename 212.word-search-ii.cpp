/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution
{
    class trie
    {
    private:
        map<char, trie *> nodeList;
        bool isTerminal;

    public:
        trie()
        {
            isTerminal = false;
        }
        void insert(string s)
        {
            trie *curr = this;
            for (auto &ch : s)
            {
                if (curr->nodeList.find(ch) == curr->nodeList.end())
                    curr->nodeList[ch] = new trie();
                curr = curr->nodeList[ch];
            }
            curr->isTerminal = true;
        }
        int checkPrefix(string s)
        {
            trie *curr = this;
            for (auto &ch : s)
            {
                if (curr->nodeList.find(ch) != curr->nodeList.end())
                    curr = curr->nodeList[ch];
                else
                    return 0; // nothing found
            }
            if (curr->isTerminal == true)
                return 2; // word found
            return 1;     // prefix found
        }
    };

    void dfs(vector<vector<char>> &board, trie *dict, set<string> &vs, string out, int i, int j, const int &row, const int &col)
    {
        if ((i < 0) or (j < 0) or (i >= row) or (j >= col))
            return;
        if (board[i][j] == ' ') // if used return
            return;
        out.push_back(board[i][j]);
        int prefix = dict->checkPrefix(out);
        if (prefix == 0)
            return;
        if (prefix == 2)
            vs.emplace(out);
        board[i][j] = ' '; // marking used
        dfs(board, dict, vs, out, i + 1, j, row, col);
        dfs(board, dict, vs, out, i, j + 1, row, col);
        dfs(board, dict, vs, out, i, j - 1, row, col);
        dfs(board, dict, vs, out, i - 1, j, row, col);
        board[i][j] = out.back(); // backtracking
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        set<string> vs;
        int row = board.size(), col = board[0].size();
        if (row == 0 or col == 0)
            return vector<string>{};
        trie *dictionary = new trie();
        for (auto &word : words)
            dictionary->insert(word);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                dfs(board, dictionary, vs, "", i, j, row, col);
        return vector<string>(vs.begin(), vs.end());
    }
};
// @lc code=end
