/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    long long prev = INT_MIN, ans = INT_MAX;
    int getMinimumDifference(TreeNode *root)
    {
        if (not root)
            return 0;
        getMinimumDifference(root->left);
        ans = min(root->val - prev, ans);
        prev = root->val;
        getMinimumDifference(root->right);
        return ans;
    }
};
// @lc code=end
