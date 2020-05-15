/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return nullptr;
        while (head and head->val == val)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        if (!head)
            return head;
        ListNode *temp = head;
        while (temp->next)
        {
            if (temp->next->val == val)
            {
                ListNode *toDel = temp->next;
                temp->next = toDel->next;
            }
            else
                temp = temp->next;
        }
        return head;
    }
};
// @lc code=end
