/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool isSameTree(TreeNode *a, TreeNode *b)
    {
        if (a == nullptr or b == nullptr)
            return a == nullptr and b == nullptr;
        return a->val == b->val and isSameTree(a->left, b->left) and isSameTree(a->right, b->right);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (not root)
            return false;
        return isSameTree(root, subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};
// @lc code=end
