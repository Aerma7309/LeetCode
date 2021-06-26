/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 */

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
    pair<TreeNode *, TreeNode *> bToLLHelper(TreeNode *root)
    {
        if (not root)
            return {nullptr, nullptr};
        if (not root->left and not root->right)
            return {root, root};
        auto l = bToLLHelper(root->left);
        auto r = bToLLHelper(root->right);
        if (not l.first)
        {
            root->right = r.first;
            root->left = nullptr;
            r.first->left = nullptr;
            return {root, r.second};
        }
        if (not r.first)
        {
            root->right = l.first;
            root->left = nullptr;
            l.first->left = nullptr;
            return {root, l.second};
        }
        root->right = l.first;
        root->left = nullptr;
        l.second->right = r.first;
        r.first->left = nullptr;
        return {root, r.second};
    }
    void flatten(TreeNode *root)
    {
        root = bToLLHelper(root).first;
    }
};
// @lc code=end
