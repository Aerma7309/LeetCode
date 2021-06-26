/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (not root)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        while (not q.empty())
        {
            int sz = q.size();
            TreeNode *node = nullptr;
            for (int i = 0; i < sz; i++)
            {
                node = q.front();
                if (i == sz - 1)
                    res.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
            }
        }
        return res;
    }
};
// @lc code=end
