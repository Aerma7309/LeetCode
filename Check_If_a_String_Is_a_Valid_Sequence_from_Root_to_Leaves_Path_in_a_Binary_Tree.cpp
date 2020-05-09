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
    bool isValidSequenceUtil(TreeNode *root, vector<int> &arr, int pos)
    {
        if (pos == arr.size() - 1 and !root->left and !root->right and root->val == arr[pos])
            return true;
        if (pos >= arr.size() or !root)
            return false;
        if (root->val == arr[pos])
        {
            bool l = false, r = false;
            if (root->left)
                l = isValidSequenceUtil(root->left, arr, pos + 1);
            if (root->right)
                r = isValidSequenceUtil(root->right, arr, pos + 1);
            if (l or r)
                return true;
        }
        return false;
    }

    bool isValidSequence(TreeNode *root, vector<int> &arr)
    {
        if (!root or arr.size() == 0)
            return false;
        return isValidSequenceUtil(root, arr, 0);
    }
};