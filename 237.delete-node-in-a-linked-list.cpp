/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node;
        while (temp->next and temp->next->next)
        {
            swap(temp->val, temp->next->val);
            temp = temp->next;
        }
        swap(temp->val, temp->next->val);
        delete (temp->next);
        temp->next = nullptr;
    }
};
// @lc code=end
