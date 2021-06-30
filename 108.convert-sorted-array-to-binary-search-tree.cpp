/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode *sortedArrayToBSTHelper(vector<int> &nums, int s, int e)
    {

        if (s > e)
            return nullptr;
        int mid = (s + e + 1) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTHelper(nums, s, mid - 1);
        root->right = sortedArrayToBSTHelper(nums, mid + 1, e);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
