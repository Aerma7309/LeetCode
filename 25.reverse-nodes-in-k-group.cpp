/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (not head)
            return head;
        ListNode *prev = nullptr, *curr = head;
        int cnt = 0;
        while (curr and cnt < k)
        {
            cnt++;
            prev = curr;
            curr = curr->next;
        }
        if (cnt < k)
            return head;
        prev->next = nullptr;
        ListNode *rev = reverse(head);
        ListNode *rem = reverseKGroup(curr, k);
        //head is last node after reverse
        head->next = rem;
        return rev;
    }
};
// @lc code=end
