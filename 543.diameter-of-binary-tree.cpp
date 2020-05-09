/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    // int height(TreeNode *root)
    // {
    //     if (!root)
    //         return 0;
    //     return max(height(root->left), height(root->right)) + 1;
    // }

    // int diameterOfBinaryTree(TreeNode *root)
    // {
    //     if (!root)
    //         return 0;
    //     int l = diameterOfBinaryTree(root->left);
    //     int r = diameterOfBinaryTree(root->right);
    //     int c = height(root->left) + height(root->right);
    //     return max({c, l, r});
    // }

    pair<int, int> diameterOfBinaryTreeUtil(TreeNode *root)
    {
        /**
         * first = height
         * second = diameter
        */
        if (!root)
            return {0,0};
        pair<int, int> l = diameterOfBinaryTreeUtil(root->left);
        pair<int, int> r = diameterOfBinaryTreeUtil(root->right);
        int h = max(l.first,r.first) + 1;
        int d = max({l.second,r.second,l.first+r.first});
        return {h,d};
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        pair<int, int> res = diameterOfBinaryTreeUtil(root);
        return res.second;
    }
};
// @lc code=end

