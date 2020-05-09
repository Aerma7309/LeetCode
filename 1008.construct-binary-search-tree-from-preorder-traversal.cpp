/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
class Solution {
public:
    TreeNode *insertInBst(TreeNode *root, int data)
    {
        if (!root)
            return new TreeNode(data);
        if (root->val > data)
            root->left = insertInBst(root->left, data);
        else
            root->right = insertInBst(root->right, data);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() == 0)
            return nullptr;
        TreeNode *root = nullptr;
        for (auto i : preorder)
            root = insertInBst(root, i);
        return root;
    }
};
// @lc code=end

