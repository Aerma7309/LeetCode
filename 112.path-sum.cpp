/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode *root, int targetSum, int currSum = 0)
    {
        if (not root)
            return false;
        if (not root->left and not root->right)
            return targetSum == currSum + root->val;
        bool left = hasPathSum(root->left, targetSum, currSum + root->val);
        bool right = hasPathSum(root->right, targetSum, currSum + root->val);
        return left or right;
    }
};
// @lc code=end
