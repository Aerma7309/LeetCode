/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */
#include <bits/stdc++.h>
using namespace std;
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
private:
    vector<vector<int>> res;
    void dfs(TreeNode *root, int targetSum, vector<int> &path)
    {
        if (not root)
            return;
        path.push_back(root->val);
        if (not root->left and not root->right and root->val == targetSum)
        {
            res.push_back(path);
            path.pop_back();
            return;
        }
        dfs(root->left, targetSum - root->val, path);
        dfs(root->right, targetSum - root->val, path);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        dfs(root, targetSum, path);
        return res;
    }
};
// @lc code=end
