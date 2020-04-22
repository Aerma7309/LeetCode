class Solution
{
public:
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);
        int c = height(root->left) + height(root->right);
        return max({c, l, r});
    }
};