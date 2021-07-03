/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
    long long  prev = INT_MIN, ans = INT_MAX;
    int minDiffInBST(TreeNode *root)
    {
        if (not root)
            return 0;
        minDiffInBST(root->left);
        ans = min(root->val - prev, ans);
        prev = root->val;
        minDiffInBST(root->right);
        return ans;
    }
};
// @lc code=end
