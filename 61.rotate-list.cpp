// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem61.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        if (!head or (k % len) == 0)
            return head;
        k = (k % len);
        int togo = len - k - 1;
        temp = head;
        while (togo--)
            temp = temp->next;
        ListNode *newHead = temp->next;
        temp->next = nullptr;
        temp = newHead;
        while (temp->next)
            temp = temp->next;
        temp->next = head;
        return newHead;
    }
};
// @lc code=end
