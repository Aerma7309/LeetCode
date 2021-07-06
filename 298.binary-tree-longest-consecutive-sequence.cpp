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

    void longestConsecutiveHelper(TreeNode *root, int nxt, int cnt, int &ans)
    {
        if (not root)
            return;
        if (root->val == nxt)
            cnt++;
        else
            cnt = 1;
        ans = max(ans, cnt);
        longestConsecutiveHelper(root->left, root->val + 1, cnt, ans);
        longestConsecutiveHelper(root->right, root->val + 1, cnt, ans);
    }

    int longestConsecutive(TreeNode *root)
    {
        int ans = 0;
        longestConsecutiveHelper(root, 0, 0, ans);
        return ans;
    }
};