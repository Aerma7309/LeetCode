/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> v;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        dfs(root);
        return v;
    }

    // vector<int> inorderTraversal(TreeNode *root)
    // {
    //     vector<int> v;
    //     map<TreeNode *, bool> visited;
    //     if (!root)
    //         return v;
    //     stack<TreeNode *> stk;
    //     stk.push(root);
    //     while (!stk.empty())
    //     {
    //         if (stk.top()->left and !visited[stk.top()->left])
    //             stk.push(stk.top()->left);
    //         else
    //         {
    //             TreeNode *t = stk.top();
    //             stk.pop();
    //             v.push_back(t->val);
    //             visited[t] = true;
    //             if (t->right)
    //                 stk.push(t->right);
    //         }
    //     }
    //     return v;
    // }
};
// @lc code=end
