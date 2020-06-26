/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    void sumNumberHelper(TreeNode *root, int curr, int &total)
    {
        if (!root)
            return;
        if (root and !root->left and !root->right)
        {
            total += (curr * 10 + root->val);
            return;
        }
        sumNumberHelper(root->left, curr * 10 + root->val, total);
        sumNumberHelper(root->right, curr * 10 + root->val, total);
    }

    int sumNumbers(TreeNode *root)
    {
        int res = 0;
        sumNumberHelper(root, 0, res);
        return res;
    }
};
// @lc code=end
