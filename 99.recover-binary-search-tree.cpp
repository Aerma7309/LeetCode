/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode;
// struct TreeNode;
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
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
    void findIrregularity(TreeNode *root)
    {
        if (not root)
            return;
        findIrregularity(root->left);
        if (prev and root->val < prev->val and not first)
            first = prev;
        if (first and root->val < prev->val)
            second = root;
        prev = root;
        findIrregularity(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        findIrregularity(root);
        swap(first->val, second->val);
    }
};
// @lc code=end