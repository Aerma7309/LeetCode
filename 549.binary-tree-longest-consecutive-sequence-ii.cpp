#include <bits/stdc++.h>
using namespace std;
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution
{
public:
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int max_len;

    pair<int, int> dfs(TreeNode *node, TreeNode *par = nullptr)
    {
        if (not node)
            return {0, 0};
        pair<int, int> left = dfs(node->left, node);
        pair<int, int> right = dfs(node->right, node);
        max_len = max({max_len, left.first + right.second + 1, left.second + right.first + 1});
        if (par)
        {
            if (node->val + 1 == par->val)
                return {max(left.first, right.first) + 1, 0};
            if (node->val - 1 == par->val)
                return {0, max(left.second, right.second) + 1};
        }
        return {0, 0};
    }

    int longestConsecutive2(TreeNode *root)
    {
        if (not root)
            return 0;
        max_len = 0;
        dfs(root);
        return max_len;
    }
};