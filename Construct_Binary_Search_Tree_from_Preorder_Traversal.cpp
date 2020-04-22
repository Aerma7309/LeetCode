class Solution
{
public:
    TreeNode *insertInBst(TreeNode *root, int data)
    {
        if (!root)
            return new TreeNode(data);
        if (root->val > data)
            root->left = insertInBst(root->left, data);
        else
            root->right = insertInBst(root->right, data);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() == 0)
            return nullptr;
        TreeNode *root = nullptr;
        for (auto i : preorder)
            root = insertInBst(root, i);
        return root;
    }
};