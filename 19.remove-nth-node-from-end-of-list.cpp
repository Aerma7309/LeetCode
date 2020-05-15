/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        while (n--)
            fast = fast->next;
        if (!fast)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode *slow = head;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return head;
    }
};
// @lc code=end
