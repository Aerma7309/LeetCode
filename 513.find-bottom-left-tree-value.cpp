/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode;
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
    int findBottomLeftValue(TreeNode *root)
    {
        if (not root)
            return -1;
        queue<TreeNode *> q;
        q.push(root);
        int ans;
        while (not q.empty())
        {
            int sz = q.size();
            TreeNode *node = q.front();
            ans = node->val;
            for (int i = 0; i < sz; i++)
            {
                node = q.front();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
            }
        }
        return ans;
    }
};
// @lc code=end
