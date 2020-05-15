/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *evenHead = nullptr, *oddHead = nullptr, *evenTail = nullptr, *oddTail = nullptr;
        bool isOdd = true;
        if (!head or !head->next)
            return head;
        ListNode *curr = head->next->next;
        head->next->next = nullptr;
        evenHead = evenTail = head->next;
        head->next = nullptr;
        oddHead = oddTail = head;
        while (curr)
        {
            if (isOdd)
            {
                oddTail->next = curr;
                oddTail = curr;
                curr = curr->next;
                oddTail->next = nullptr;
            }
            else
            {
                evenTail->next = curr;
                evenTail = curr;
                curr = curr->next;
                evenTail->next = nullptr;
            }
            isOdd=(!isOdd);
        }
        oddTail->next = evenHead;
        return oddHead;
    }
};
// @lc code=end
