/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{

public:
    // Encodes a tree to a single string.
    void preorder_traverse(TreeNode *root, stringstream &ss)
    {
        if (not root)
            return;
        ss << root->val << ' ';
        preorder_traverse(root->left, ss);
        preorder_traverse(root->right, ss);
    }

    string serialize(TreeNode *root)
    {
        stringstream ss;
        preorder_traverse(root, ss);
        return ss.str();
    }

    TreeNode *buildBST(vector<int> &v, int &idx, int mx, int mn)
    {

        if (idx < 0 or idx >= v.size())
            return nullptr;
        TreeNode *node = nullptr;
        int curr = v[idx];
        if (curr < mx and curr > mn)
        {
            node = new TreeNode(curr);
            idx++;
            node->left = buildBST(v, idx, curr, mn);
            node->right = buildBST(v, idx, mx, curr);
        }
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<int> v;
        string num;
        stringstream ss(data);
        while (ss >> num)
            v.push_back(stoi(num));
        int idx = 0;
        return buildBST(v, idx, INT_MAX, INT_MIN);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
