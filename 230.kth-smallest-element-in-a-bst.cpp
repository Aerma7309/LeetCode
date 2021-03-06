/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int cnt = 0, ans;
    void InOrder(TreeNode *root, int k)
    {
        if (!root)
            return;
        InOrder(root->left, k);
        if (++cnt == k)
        {
            ans = root->val;
            return;
        }
        InOrder(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        InOrder(root, k);
        return ans;
    }
};
// @lc code=end
