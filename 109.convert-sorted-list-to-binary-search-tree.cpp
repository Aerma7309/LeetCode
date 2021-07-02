/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int lengthLL(ListNode *head)
    {
        int cnt = 0;
        while (head)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

public:
    TreeNode *sortedListToBSTHelper(ListNode *head, int s, int e)
    {
        if (s > e)
            return nullptr;
        int mid = (s + e + 1) / 2, cnt = 0;
        ListNode *prev = nullptr, *curr = head;
        while (curr and cnt < mid)
        {
            cnt++;
            prev = curr;
            curr = curr->next;
        }
        TreeNode *root = new TreeNode(curr->val);
        root->left = sortedListToBSTHelper(head, s, mid - 1);
        root->right = sortedListToBSTHelper(curr->next, 0, e - (mid + 1));
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        int length = lengthLL(head);
        return sortedListToBSTHelper(head, 0, length - 1);
    }
};
// @lc code=end
