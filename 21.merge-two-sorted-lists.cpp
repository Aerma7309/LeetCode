// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem21.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr, *tail = nullptr;
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val < l2->val)
        {
            head = tail = l1;
            l1 = l1->next;
            // head->next = nullptr;
        }
        else
        {
            head = tail = l2;
            l2 = l2->next;
            // head->next = nullptr;
        }

        while (l1 and l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        while (l1)
        {
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }

        while (l2)
        {
            tail->next = l2;
            l2 = l2->next;
            tail = tail->next;
        }
        tail->next = nullptr;
        return head;
    }
};
// @lc code=end
