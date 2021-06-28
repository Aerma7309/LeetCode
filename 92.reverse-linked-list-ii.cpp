/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (not head)
            return head;
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        int cnt = 1;
        while (curr and cnt < left)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (prev)
            prev->next = nullptr;
        ListNode *l1end = prev, *l2start = curr;
        while (curr and cnt <= right)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (prev)
            prev->next = nullptr;
        ListNode *l2rev = reverse(l2start);
        if (l2start)
            l2start->next = curr;
        if (not l1end)
            return l2rev;
        l1end->next = l2rev;
        return head;
    }
};
// @lc code=end
