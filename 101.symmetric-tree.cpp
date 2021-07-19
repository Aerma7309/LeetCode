/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
public:
    // bool isSymmetricHelper(TreeNode *root, TreeNode *temp)
    // {
    //     if (not root or not temp)
    //         return root == temp;
    //     return root->val == temp->val and isSymmetricHelper(root->left, temp->right) and isSymmetricHelper(root->right, temp->left);
    // }
    // bool isSymmetric(TreeNode *root)
    // {
    //     return isSymmetricHelper(root, root);
    // }

    bool isSymmetric(TreeNode *root)
    {
        if (not root)
            return true;
        queue<TreeNode *> q;
        vector<int> data;
        q.push(root);
        int valid = 1;
        while (not q.empty() and valid > 0)
        {
            int sz = q.size();
            data.clear();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp)
                {
                    valid--;
                    q.push(temp->left);
                    q.push(temp->right);
                    if (temp->right)
                        valid++;
                    if (temp->left)
                        valid++;
                    data.push_back(temp->left ? temp->left->val : INT_MIN);
                    data.push_back(temp->right ? temp->right->val : INT_MIN);
                }
                else
                {
                    data.push_back(INT_MIN);
                    data.push_back(INT_MIN);
                }
            }
            for (int i = 0; i < data.size() / 2; i++)
                if (data[i] != data[data.size() - i - 1])
                    return false;
        }
        return true;
    }
};
// @lc code=end
