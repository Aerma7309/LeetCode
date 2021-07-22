/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    vector<string> res;
    void dfs(TreeNode *root, string path = "")
    {
        if (not root)
            return;
        path += to_string(root->val);
        if (not root->left and not root->right)
        {
            res.push_back(path);
            return;
        }
        path += "->";
        dfs(root->left, path);
        dfs(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        dfs(root);
        return res;
    }
};
// @lc code=end
