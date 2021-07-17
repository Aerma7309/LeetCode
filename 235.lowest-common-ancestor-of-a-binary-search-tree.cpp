/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // algorith used in binary tree
        // if (not root or root->val == p->val or root->val == q->val)
        //     return root;
        // auto left = lowestCommonAncestor(root->left, p, q);
        // auto right = lowestCommonAncestor(root->right, p, q);
        // if (left and right)
        //     return root;
        // if (left)
        //     return left;
        // return right;

        // using BST Properties
        if (not root)
            return nullptr;
        if (root->val > p->val and root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val and root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
// @lc code=end
