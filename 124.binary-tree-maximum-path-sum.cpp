/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int res = INT_MIN;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int v = root->val;
        int mx = max(l, r) + v;
        res = max({res, l + r + v});
        return max(mx, 0);
    }

    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;
        dfs(root);
        return res;
    }
};
// @lc code=end

