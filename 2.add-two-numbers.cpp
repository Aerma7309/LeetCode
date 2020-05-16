/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *head, *tail;
        head = tail = new ListNode((l1->val + l2->val) % 10);
        carry = (l1->val + l2->val) / 10;
        ListNode *currl1 = l1->next, *currl2 = l2->next;
        while (currl1 and currl2)
        {
            int t = currl1->val + currl2->val + carry;
            tail->next = new ListNode(t % 10);
            carry = t / 10;
            currl1 = currl1->next;
            currl2 = currl2->next;
            tail = tail->next;
        }
        while (currl1)
        {
            int t = currl1->val + carry;
            tail->next = new ListNode(t % 10);
            carry = t / 10;
            currl1 = currl1->next;
            tail = tail->next;
        }
        while (currl2)
        {
            int t = currl2->val + carry;
            tail->next = new ListNode(t % 10);
            carry = t / 10;
            currl2 = currl2->next;
            tail = tail->next;
        }
        if (carry > 0)
            tail->next = new ListNode(carry);
        return head;
    }
};
// @lc code=end
