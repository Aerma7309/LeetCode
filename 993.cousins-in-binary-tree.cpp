/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
    map<int, int[2]> parent;
    void buildParent(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
            parent[root->left->val][0] = root->val, parent[root->left->val][1] = parent[root->val][1] + 1;
        if (root->right)
            parent[root->right->val][0] = root->val, parent[root->right->val][1] = parent[root->val][1] + 1;
        buildParent(root->left);
        buildParent(root->right);
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        parent[root->val][0] = parent[root->val][1] = 0;
        buildParent(root);
        // for(auto i: parent) cout<<i.first<<" "<<i.second[0]<<" "<<i.second[1]<<'\n';
        return (parent[x][0] != parent[y][0] and parent[x][1] == parent[y][1]);
    }
};
// @lc code=end
