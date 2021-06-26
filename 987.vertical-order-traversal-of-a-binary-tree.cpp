/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        if (not root)
            return {{}};
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        map<int, vector<int>> m;
        int depth = 0;
        while (not q.empty())
        {
            int sz = q.size();
            map<int, vector<int>> lm;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front().first;
                int hd = q.front().second;
                if (node->left)
                    q.push({node->left, hd - 1});
                if (node->right)
                    q.push({node->right, hd + 1});
                lm[hd].push_back(node->val);
                q.pop();
            }
            for (auto &i : lm)
            {
                sort(i.second.begin(), i.second.end());
                for (auto &j : i.second)
                    m[i.first].push_back(j);
            }
            depth++;
        }
        vector<vector<int>> res;
        for (auto &i : m)
            res.push_back(i.second);
        return res;
    }
};
// @lc code=end
