/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head)
    {
        if (!head or !head->next)
            return nullptr;
        ListNode *slow = head, *fast = head;
        while (fast and fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (slow != fast)
            return nullptr;
        if(fast==head) return head;
        slow = head;
        while (slow->next != fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast->next;
    }
};
// @lc code=end
