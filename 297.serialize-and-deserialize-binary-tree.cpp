// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem297.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
    string serialize(TreeNode *root)
    {
        if (not root)
            return "null";
        stringstream ss;
        queue<TreeNode *> q;
        q.push(root);
        int valid = 1;
        while (not q.empty() and valid > 0)
        {
            TreeNode *node = q.front();
            if (node)
            {
                ss << node->val << ' ';
                if (node->left)
                    valid++;
                if (node->right)
                    valid++;
                q.push(node->left);
                q.push(node->right);
            }
            else
                ss << "null ";
            if (node)
                valid--;
            q.pop();
        }
        return ss.str();
    }

    TreeNode *deserialize(string data)
    {
        stringstream ss(data);
        string s;
        queue<TreeNode *> q;
        vector<string> v;
        int curr = 0;
        while (ss >> s)
            v.emplace_back(s);
        TreeNode *root = nullptr;
        if (v[curr] != "null")
            root = new TreeNode(stoi(v[curr++]));
        q.push(root);
        while (not q.empty() and curr < v.size())
        {
            TreeNode *node = q.front();
            if (v[curr] != "null")
            {
                node->left = new TreeNode(stoi(v[curr]));
                q.push(node->left);
            }
            curr++;
            if (curr >= v.size())
                break;
            if (v[curr] != "null")
            {
                node->right = new TreeNode(stoi(v[curr]));
                q.push(node->right);
            }
            curr++;
            q.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
